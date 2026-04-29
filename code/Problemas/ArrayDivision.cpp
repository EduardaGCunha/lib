//Array Division
int n, m; cin >> n >> m;
int mx;
for(int i = 0; i < n; i++){
    int a; cin >> a;
    mx = max(mx, a);
    arr[i] = a;
}
int l = mx, r = 2e18;
while(l < r){
    int mid = (l+r)/2;
    int i = 0, sum = 0, c = 0;
    while(i < n){
        if(sum + arr[i] > mid){
            sum = 0; 
            c++;
        }
        sum += arr[i];
        i++;
    }
    if(c < m){
        r = mid;
    }else{
        l = mid+1;
    }
}

cout << r << endl;