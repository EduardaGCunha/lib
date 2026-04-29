//Sum of Divisors
const int MOD = 1e9+7;
const int MAXN = 1e6+7;
const int TWO_MOD_INV = 500000004;
 
//(b-a+1)*(a+b)2W
 
int sum(int a, int b){
    return (((((b-a+1)%MOD) * ((a+b)%MOD))%MOD * (TWO_MOD_INV))%MOD);
}
 
signed main(){
	fastio;
    int n; cin >> n;
    int ans = 0;
    int i = 1;
    while(i <= n){
        int quotient = n/i;
        int last = n/quotient;
 
        ans = (ans + quotient*(sum(i, last)))%MOD;
        i = last+1;
    }
    cout << ans << endl;
 
}