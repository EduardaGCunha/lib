//Coins Combinations II
void pd(){
    int n, k; cin >> n >> k;
    int c[n];
    for(int i = 0; i < n; i++) cin >> c[i];
 
    vector<int> dp(k+1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= k; j++){
            if(j - c[i]>=0){
                dp[j] += dp[j-c[i]];
                dp[j] %=MOD;
            }
        }
    }
 
    cout << dp[k] << endl;
}