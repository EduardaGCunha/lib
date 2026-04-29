//Euler Tour
//O(V+E)
const int MAXN = 2*(1e5)+7;
vector<int> graph[MAXN];
int tin[MAXN], tout[MAXN], visited[MAXN];
int timer = 0;
void dfs(int v){
    tin[v] = ++timer;
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u]) dfs(u);
    }
    tout[v] = timer;
}