using int64 = long long;
 
const int64 B = 911382323LL;
const int64 MOD = 1e9+9;
const int MAXN = 1e6+6;
int64 h[MAXN], pref[MAXN];
 
signed main(){
	fastio;
	string s, t; cin >> s >> t;
 
    int n = s.size(), m = t.size();
    if(m > n){
        cout << 0 << endl;
        return 0;
    }
    //preocmputing the powers
    pref[0] = 1;
    h[0] = s[0];
    for(int i = 1; i <= n; i++){
        pref[i] = (pref[i-1]*B)%MOD;
    }
 
    for(int i = 0; i < n; i++){
        h[i+1] = (h[i]*B + (s[i]-'a'+1))%MOD;
    }
 
    int64 ph = 0;
    for(int i = 0; i < m; ++i){
        ph = (ph* B + (t[i] - 'a'+1))%MOD;
    }
 
    int ans = 0;
    for(int i = 0; i + m <= n; i++){
        int64 hash = (h[i+m] - (h[i]*pref[m])%MOD + MOD)%MOD;
        if(hash == ph) ans++;
    }
    cout << ans << endl;
}