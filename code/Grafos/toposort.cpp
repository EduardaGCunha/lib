//Kahns Algorithm 
//Time Complexity: O(V + E)
//Remember to fill indeg array and check MAXN
const int MAXN = 2*1e5+8;
vector<int> graph[MAXN];
int indeg[MAXN];
void topo(){
    int n;
    queue<int> pq;
    for(int i = 0; i < n; i++){
        if(!indeg[i]) pq.push(i);
    }

    vector<int> toposort;
    while(!pq.empty()){
        auto v = pq.front(); pq.pop();
        toposort.push_back(v);
        for(auto u : graph[v]){
            if(--indeg[u] == 0) pq.push(u);
        }
    }
}