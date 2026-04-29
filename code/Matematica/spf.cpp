//Smallest Prime Factor

const int MAXN = 1e6+7;
int spf[MAXN];

void mfp(){
    //preenche spf[i] com i
    iota(spf, spf+MAXN, 0);
    for(int i = 2; i*i < MAXN; i++){
        if(spf[i] == i){
            for(int j = i*i; j < MAXN; j += i){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}