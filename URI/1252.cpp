#include <bits/stdc++.h>

using namespace std;

int M;

int cmp(int x, int y) {
    if (x%M == y%M) {
        if(abs(x)%2 == abs(y)%2) {
            if (x%2 != 0) return x > y;
            else return x < y;
        }
        return abs(x)%2 > abs(y)%2; 
    }
    return x%M < y%M; 
}

int main() {
    int n;
    while(scanf("%d %d", &n, &M), n&&M){
        int arr[n];
        int i;
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        printf("%d %d\n", n, M);
        sort(arr, arr+n, cmp);
        for (i = 0; i < n; i++) {
            printf("%d\n", arr[i]);
        }
    }
    printf("0 0\n");
    return 0;
}