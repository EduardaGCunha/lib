//Fatorial e Inverso Modular
const int MAXN = 1e6+1;
const int MOD = 1e9+7;
int fat[MAXN], inv[MAXN];

void fact(){
    fat[0] = 1;
    inv[0] = 1;
    for(int i = 1; i < MAXN; i++){
        fat[i] = (fat[i-1] * i) % MOD;
        inv[i] = fastexpo(fat[i], MOD-2);
    }
}

//para calcular o inv[val], basta joga-lo no fastexpo com MOD-2
//para dividir um valor sob mod, basta pegar o multiplicar val * inv[val]
