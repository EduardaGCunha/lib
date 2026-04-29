//Biconnected Components
// Acha as bridges do grafo e monta a bridge tree

void novaComponenteBiconexa(int idAresta){
    c++;
    int a;
    do {
        a = pilhaArestas[p];
        p--;
        componenteDaAresta[a] = c;
        if(p == -1) break;
    }while(a != idAresta);
}

void dfs(int v, int p){
    visited[v] = 1;
    low[v] = pre[v] = ++t;
    int qtdFilhos = 0;
    for (auto u : graph[v]){
        int viz = graph[v][i];
        int idAresta = aresta[v][i];
        if(visitedAresta[idAresta] == 1) continue;
        visitedAresta[idAresta] = 1;
        p++;
        pilhaAresta[p] = idAresta;
        if (!visited[u]){
            dfs(u,v);
            low[v] = min(low[v], low[u]);

            bool achouNovaComponente = false;
            if(v == 1 && qtdFilhos >= 2) achouNovaComponente = false;
            if(v != 1 && low[u] >= low[v]) achouNovaComponente = true;

            if(achouNovaComponente){
                pontoDeArticulacao[v] = 1;
                novaComponenteBiconexa(idAresta);
            }
        }   
        else {
            low[v] = min(low[v], pre[u]);
        }
    }
}


//t = 0, p = -1, c = 0;
//dfs(0, 0);
//novaComponenteBiconexa(-1);
