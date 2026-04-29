//Floyd-Warshall
//Acha a distância entre qualquer 2 vertices
//O(N^3)

const int MAXN = 503;
int graph[MAXN][MAXN];
int dist[MAXN][MAXN];
 
const int INF = 1e13;
void floydwarshal(){
    int n, m, q; cin >> n >> m >> q;
    //leitura do grafo
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= n; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    for(int i = 1; i <= m; i++){
        int a, b, c; cin >> a >> b >> c;
        if(dist[a][b] > c) dist[a][b] = dist[b][a] = c; 
    }
 
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}