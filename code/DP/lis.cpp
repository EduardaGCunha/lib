//Longest Increasing Subsequence

void lis(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
 
    vector<int> dp;
    for(int i = 0; i < n; i++){
        int pos = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        if(pos == (int) dp.size()){
            dp.push_back(arr[i]);
        }else{
            dp[pos] = arr[i];
        }
    }
 
    cout << dp.size() << endl;
}

//lis recuperando a sequencia

void lis2(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    map<int, int> dp; 

    int ans = 0; 
    int lst = 0;
    for(int i = 0; i < n; i++){
        dp[arr[i]] = dp[arr[i]-1] + 1;
        if(ans < dp[arr[i]]){
            ans = dp[arr[i]];
            lst = arr[i]; 
        }
       
    }

    vector<int> res;
    for(int i = n-1; i>=0; i--){
        if(arr[i] == lst){
            res.push_back(i);
            lst--;
        }
    }

    cout << ans << endl;
    reverse(res.begin(), res.end());
    for(auto u : res){
        cout << u+1 << " ";
    }
}