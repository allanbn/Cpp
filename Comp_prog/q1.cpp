#include <bits/stdc++.h>

using namespace std;

#define lli long long int
const lli mod = ((1 << 31)-1);

lli exp(lli x, lli y){
    if(y == 0) return 1;
    if(y & 1) 
        return ((x%mod) * (exp((x%mod)*(x%mod)%mod, y>>1)%mod)) % mod;
    return exp((x%mod)*(x%mod)%mod, y>>1)%mod;
}


int main(){
    lli n;
    while(scanf("%lld", &n) != EOF){
        printf("%lld\n", exp(3, n));
    }
    return 0;
}