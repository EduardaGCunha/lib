//2D Prefix Sum
void prefixsum2D(){
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char a; cin >> a;
            if(a == '*')grid[i][j]++;
        }
    }
 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
        }
    }
    while(q--){
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        //pega 
        cout << grid[y2][x2] - grid[y1-1][x2] - grid[y2][x1-1] + grid[y1-1][x1-1] << endl;
    }

}