//Edit Distance
const int MAXN = 1e5;
int dp[MAXN];
void editdistance(){
    int n, m;
    for(int i = 0, cnt = 0; i <= max(n, m); i++, cnt++){
        dp[i][0] = cnt;
        dp[0][i] = cnt;
    }
 
    //dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                int mn = min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}) + 1;
                dp[i][j] = mn;
            }
        }
    }
}
