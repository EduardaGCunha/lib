//Binary Search
bool check(int mid){

}
 
void binarysearch(){
    int l = 1, r = 1e18;
    while(l < r){
        int mid = l+(r-l)/2;
        if(check(mid)) r = mid;
        else l = mid+1;
    }  
}