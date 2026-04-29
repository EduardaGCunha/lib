//SegTree
//upd: O(logN)
//query: O(logN)

template<typename T>

struct segtree{
    int n;
    vector<int> t;
    void init(int _n){
        n = _n;
        t.assign(4*n, 0);
    }

    T op(T a, T b){
        return min(a, b);
    }

    void build(vector<int> &arr, int v, int l, int r){
        if(l == r){
            t[v] = arr[l];
            return;
        }
        int m = (l+r)/2;
        build(arr, 2*v+1, l, m);
        build(arr, 2*v+2, m+1, r);
        t[v] = op(t[2*v+1], t[2*v+2]);
    }

    void build(vector<int> &arr){
        build(arr, 0, 0, n-1);
    }

    int query(int v, int l, int r, int ql, int qr){
        if(qr < l || r < ql) return 0;
        if(ql <= l && r <= qr) return t[v];
        int m = (l+r)/2;
        return op(query(2*v+1, l, m, ql, qr), query(2*v+2, m+1, r, ql, qr));
    }

    int query(int l,    int r){
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
        t[v] = op(t[2*v+1], t[2*v+2]);
    }

    void update(int idx, int x){
        update(0, 0, n-1, idx, x);
    }
};