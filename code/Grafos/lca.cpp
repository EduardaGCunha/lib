//LCA
//query: O(logN)
const int MAXL = 20;
const int MAXN = 2 * (int)(1e5) + 7;
vector<int> graph[MAXN];
int depth[MAXN], anc[MAXN][MAXL];

void dfs(int v, int p) {
    anc[v][0] = p;  
    depth[v] = depth[p] + 1;
    for (int i = 1; i < MAXL; i++) {
        anc[v][i] = anc[ anc[v][i-1] ][i-1];
    }
    for (auto u : graph[v]) {
        if (u != p) {   
            dfs(u, v);
        }
    }
}

int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b]; 
    for(int i = MAXL-1; i >= 0; i--){
        if(k&(1<<i)){
            a = anc[a][i];
        }
    }

    if(a == b) return a;

    for(int i = MAXL-1; i >= 0; i--){
        if(anc[a][i] != anc[b][i]){
            a = anc[a][i];
            b = anc[b][i];
        }
    }
    return anc[a][0];
}
