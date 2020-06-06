#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        long long int in;
        scanf("%lld", &in);
        if (in == 0) printf("Not Prime\n");
        else if (in == 1) printf("Not Prime\n");
        else if (in == 2) printf("Prime\n");
        else {
            long long int i, c;
            c = 0;
            for (i = 2; i < sqrt(in)+1; i++) {
                if ((in % i) == 0) c++;
                if (c==2) break;
            }
            if (c >= 1) printf("Not Prime\n");
            else printf("Prime\n");
        }
    }
    return 0;
}