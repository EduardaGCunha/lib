//Dijkstra
//O(N + M log N)
const int MAXN = 2e5+7;
const int INF = 1e18;
vector<pair<int, int>> graph[MAXN];
int dist[MAXN];
int n, m;

void dijkstra(){
    //dist, node
    priority_queue<pair<int, int>> pq;
    pq.push({0, 0}); //0 indexed
    for(int i = 0; i < MAXN; i++) dist[i] = INF;
    dist[0] = 0;
    while(!pq.empty()){
        auto [d, v] = pq.top(); pq.pop();
        d = -d;
        if(dist[v] < d) continue;
        for(auto [u, w] : graph[v]){
            if(dist[u] > dist[v] + w){
                dist[u] = dist[v] + w;
                pq.push({-dist[u], u});
            }
        }
    }
    for(int i = 0; i < n; i++) cout << dist[i] << " ";
    cout << endl;
}
