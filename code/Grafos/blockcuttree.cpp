//BlockCut Tree
//Comprimir uma Compoentne Biconexa

for(int i = 1; i <= n; i++){
    if(pontoDeArticualacao[i] != 1) continue;

    c++;
    pontoDeArticulacao[i] = c;
    for(int j = 0; j < aresta[i].size(); j++){
        int idAresta = aresta[i][j];
        int comp = componenteDaAresta[idAresta];
        if(marcComp[comp] == 0){
            marcComp[comp] = 1;
            blockCutTree[pontoDeArticulacao[i]].push_back(comp);
            blockCutTree[comp].push_back(pontoDeArticulacao[i]);
        }
    }

    for(int j = 0; j < aresta[i].size(); j++){
        int idAresta = aresta[i][j];
        int comp = componenteDaAresta[idAresta];
        marcComp[comp] = 0;
    }
}