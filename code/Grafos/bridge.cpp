//Bridge Tree
// Acha as bridges do grafo e monta a bridge tree
int t, c, low[MAX], pre[MAX], visited[MAX], comp[MAX];
stack<int> st;
vector<int> graph[MAX], compgraph[MAX];

void dfs(int v, int p){
    visited[v] = 1;
    low[v] = pre[v] = ++t;
    st.emplace(v);
    for (auto u : graph[v]){
        if (!visited[u]){
            dfs(u,v);
            low[v] = min(low[v], low[u]);
        }   
        else {
            if (u == p) continue;
            low[v] = min(low[v], pre[u]);
        }
    }
    //aq depende se ta 0 ou 1 indexado
    if (v != 0 && low[v] == pre[v]) resp.push_back({v, pai});
}