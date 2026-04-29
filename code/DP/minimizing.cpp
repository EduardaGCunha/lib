//Minimizing Coins
void pd(){
    int n, k; cin >> n >> k;
    int c[n];
    for(int i = 0; i < n; i++) cin >> c[i];
 
    vector<int> dp(k+1, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = c[i]; j <= k; j++){
            if(dp[j-c[i]] != INT_MAX)
            dp[j] = min(dp[j], dp[j-c[i]]+1);
        }
    }
    if(dp[k] == INT_MAX) cout << -1 << endl;
    else cout << dp[k] << endl;
}