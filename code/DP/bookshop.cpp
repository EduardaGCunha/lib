//Knapsack
void pd(){
    int n, m; cin >> n >> m;
    int pages[n], prices[n];
    for(int i = 0; i < n; i++) cin >> prices[i];
    for(int i = 0; i < n; i++) cin >> pages[i];
 
    vector<int> dp(m+1, 0);
    for(int i = 0; i < n; i++){
        for(int j = m; j >= prices[i]; j--){
            dp[j] = max(dp[j], dp[j-prices[i]] + pages[i]);
        }
    }

}