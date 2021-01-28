#include <bits/stdc++.h>

int main() {

    long int D, E;

    scanf("%ld %ld", &D, &E);

    int n = D;
    int c = 1;

    while ((n > 1) || (n < -1)) {
        if (n >= 1) n -= E;
        else n += D;
        c++;
    }
    
    if (!n) printf("IMPOSSIVEL\n");
    else printf("%ld\n", c);

    return 0;
}