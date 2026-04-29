//Small To Large example
const int MAXN = 2*1e5+7;
set<int> distinct[MAXN];
vector<int> graph[MAXN];
int ans[MAXN];
 
void dfs(int v, int p){ 
    for(auto u : graph[v]){
        if(u == p) continue;
        dfs(u, v);
        if(distinct[u].size() > distinct[v].size()) swap(distinct[u], distinct[v]);
        for(auto x : distinct[u]) distinct[v].insert(x);
    }
    ans[v] = distinct[v].size();
}
