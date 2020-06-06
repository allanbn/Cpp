#include <bits/stdc++.h>

int call, count;

int fib(int n) {
    call++;
    if (n==0) return 0;
    else if (n==1) {
        count++;
        return 1;
    }
    else {
        return fib(n-1) + fib(n-2);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        int x;
        call = -1;
        count = 0;
        scanf("%d", &x);
        fib(x);
        printf("fib(%d) = %d calls = %d\n", x, call, count);
    }
}