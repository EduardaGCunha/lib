//Distinct Value Queries
struct BIT {
    int n;
    vector<int> bit;
 
    void init(int _n){
        n = _n+1;
        bit.assign(n, 0);
    }
 
    void update(int x, int v){
        x++;
        for(; x <= n; x += x&(-x)) bit[x] += v;
    }
 
    int sum(int b){
        b++;
        int sum = 0;
        for(; b > 0; b -= b&(-b)) sum += bit[b];
        return sum;
    }
};
 
signed main(){
    fastio;
    int n, q; cin >> n >> q;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
 
    BIT bit;
    bit.init(n);
    map<int, vector<pair<int, int>>> mp;
    for(int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        mp[a].push_back({b, i});
    }
    //se ja apareceu e ultimo indice
    map<int, int> freq;
 
    vector<int> ans(q, -1);
    for(int i = n-1; i >= 0; i--){
        
        //se ele ja foi visto anteriormente, ent retiro a soma dele
        if(freq.count(arr[i]) > 0){
            bit.update(freq[arr[i]], -1);
        }
 
        freq[arr[i]] = i;
        bit.update(i, 1);
 
        //p/ cada query comecando em i, resposta 
        for(auto u : mp[i]){
            //cout << i << " " << u.first << " " << bit.sum(u.first) << endl; 
            ans[u.second] = bit.sum(u.first);
        }
    }
 
    for(auto u : ans) cout << u << endl;
 
}