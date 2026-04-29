//Increasing Subsequence II
struct segtree{
    int n;
    vector<int> t;
    void init(int _n){
        n = _n;
        t.assign(4*n, 0);
    }
 
    void build(vector<int> &arr, int v, int l, int r){
        if(l == r){
            t[v] = arr[l];
            return;
        }
        int m = (l+r)/2;
        build(arr, 2*v+1, l, m);
        build(arr, 2*v+2, m+1, r);
        t[v] = t[2*v+1] + t[2*v+2];
    }
 
    void build(vector<int> &arr){
        build(arr, 0, 0, n-1);
    }
 
    int query(int v, int l, int r, int ql, int qr){
        if(qr < l || r < ql) return 0;
        if(ql <= l && r <= qr) return t[v];
        int m = (l+r)/2;
        return query(2*v+1, l, m, ql, qr) + query(2*v+2, m+1, r, ql, qr);
    }
 
    int query(int l, int r){
        if(l > r) return 0;
        return query(0, 0, n-1, l, r);
    }
 
    void update(int v, int l, int r, int idx, int x){
        if(l == r){
            t[v] += x;
            return;
        }
 
        int m = (l+r)/2;
        if(idx <= m) update(2*v+1, l, m, idx, x);
        else update(2*v+2, m+1, r, idx, x);
        t[v] = t[2*v+1] + t[2*v+2];
    }
 
    void update(int idx, int x){
        update(0, 0, n-1, idx, x);
    }
};
 
signed main(){
    int n; cin >> n;
    segtree st;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
 
    vector<int> comp = v;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    // 2) now comp.size() = M < n
    // 3) to get the index of v[i] use lower_bound(comp, v[i])
    auto idx = [&](int x){
        return (lower_bound(comp.begin(), comp.end(), x) - comp.begin());
    };
 
    int ans = 0;
    vector<int> arr(n);
    st.init(comp.size());
    for(int i = 0; i < n; i++){
        int p = idx(v[i]);
        int sum = st.query(0, p-1);
        int pd = (1 + sum)%MOD;
        ans = (ans + pd)%MOD;
        st.update(p, pd);
    }
 
    cout << ans << endl;
    
}
