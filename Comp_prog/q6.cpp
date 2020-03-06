#include <bits/stdc++.h>

#define lli long long int

using namespace std;

lli sol(lli x, lli y, lli z, lli c) {
    printf("%lld\n", z);
    if (z == 1 || z == -1) return 1;
    sol(x, y, z+x, c+1);
    sol(x, y, z+y, c+1);
    sol(x, y, z-x, c+1);
    sol(x, y, z-y, c+1); 
    return 0;
}


int main() {
    lli D, E, H, c;
    c = 0;
    H = 0;
    cin >> D >> E;
    if (sol(D, E, H, c)) printf("%lld\n", c);
    return 0;
}