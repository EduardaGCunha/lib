//LCA with RMQ
//preprocessing: O(NlogN)
//query: O(1)
const int LOG = 30;
const int MAX = 1e5+7;
int n, timer = 0, tin[MAX], depth[MAX];
vector<int> et;
pair<int,int> sp[MAX*2][LOG+1];
vector<int> graph[MAX];

void dfs(int v, int p){
    
    tin[v] = et.size();
    et.push_back(v);
    for (auto u : graph[v]){
        if (u!=p){
            depth[u] = depth[v]+1;
            dfs(u,v);
            et.push_back(v);
        }
    }
}

void buildtable(){
    for (int i = 0; i < (int)et.size(); i++){
        sp[i][0] = {depth[et[i]], et[i]};
    }
    for (int j = 1; j <= LOG; j++){
        for (int i = 0; i + (1<<(j-1)) < (int)et.size(); i++){
            sp[i][j] = min(sp[i][j-1], sp[i+(1<<(j-1))][j-1]);
        }
    }
}

pair<int,int> query (int a, int b){
    int len =  b - a + 1;
    int lg = 31 - __builtin_clz(len);
    return min(sp[a][lg], sp[b - (1<<lg) + 1][lg]);
}

int lca(int a, int b){
    if (tin[a] > tin[b]) swap(a,b);
    return query(tin[a], tin[b]).second;
}
