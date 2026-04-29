//Binary Indexed Tree/Fenwick Tree
//upd: O(logN)
//query: O(logN)
struct BIT {
    int n;
    vector<int> bit;
    void init(int _n){
        n = _n+1;
        bit.resize(n, 0);
    }

    void upd(int x, int v){
        for(; x <= n; x+=x&(-x)) bit[x] += v;
    }

    int sum(int x){
        int s = 0;
        for(; x > 0; x -= x&(-x)) s += bit[x];
        return s;
    }

    int query(int l, int r){
        return sum(r) - sum(l-1);
    }
};
