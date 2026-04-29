//Divisor Analysis
const int MOD = 1e9+7;
 
int fastexpo(int a, int b){
    int res = 1;
    a%=MOD;
    while(b >= 1){
        if(b&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b >>= 1;
    }
    return res;
}
 
signed main(){
	fastio;
	int n; cin >> n;
    vector<pair<int, int>> p;
    int cnt = 1, cnt2 = 1, impar = 1;
    for(int i = 0; i < n; i++){
        int primo, exp; cin >> primo >> exp;
        p.push_back({primo, exp});
        cnt = (cnt*(exp+1))%MOD;
        cnt2 = (cnt2*(exp+1))%(2*(MOD-1));
        if(exp&1) impar = 0;
    }
 
    int sum = 1, prod = 1;
    for(int i = 0; i < n; i++){
        int exp2 = (p[i].second+1)%(MOD-1);
 
        int num = (fastexpo(p[i].first, exp2) - 1 + MOD) % MOD;
        int dem = (p[i].first-1 + MOD)%MOD;
        int inv = (fastexpo(dem, MOD-2));
        sum = (sum * ((num * inv)%MOD))%MOD;
 
        if(!impar){
            int exp = ((cnt2/2)*p[i].second)%(MOD-1);
            prod = (prod * (fastexpo(p[i].first, exp))%MOD)%MOD;
        }else{
            int exp = ((p[i].second/2)*cnt2)%(MOD-1);
            prod = (prod*(fastexpo(p[i].first, exp))%MOD)%MOD;
        }
    }
 
    cout << (cnt%MOD) << " " << (sum%MOD) << " " << (prod%MOD) << endl;
}