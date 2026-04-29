//Disjoint Set Union
//Time complexity: O(m*a(n))
//implements rank heuristic + path compression
struct DSU{
    int n;
    vector<int> p; 
    vector<int> r;
    DSU(int _n){
        n = _n; 
        p.resize(n);
        r.resize(n);
        for(int i = 0; i < n; i++){
            p[i] = i;
            r[i] = 0;
        }
    }

    int find(int x){
        return (p[x] == x? x : p[x] = find(p[x]));
    }

    void unite(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return;
        if(r[a] == r[b]) r[a]++;
        if(r[a] > r[b]){
            r[a] += r[b];
            p[b] = a;
        }else{
            r[b] += r[a];
            p[a] = b;
        }
    }
    
};