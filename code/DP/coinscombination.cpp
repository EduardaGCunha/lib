//Coins Combinations I
void pd(){
    int n, k; cin >> n >> k;
    int c[n];
    for(int i = 0; i < n; i++) cin >> c[i];
 
    vector<int> dp(k+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= k; i++){
        for(int j = 0; j < n; j++){
            if(i - c[j] >= 0){
                dp[i] += dp[i-c[j]];
                dp[i] %= MOD;
            }
        }
    }
 
    cout << dp[k] << endl;
}