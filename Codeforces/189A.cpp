#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, a, b, c; 
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int *dp = (int*)calloc(n+1, sizeof(int));
    if(a <= n) dp[a] = 1;
    if(b <= n) dp[b] = 1;
    if(c <= n) dp[c] = 1;
    int i;
    for(i = 1; i <= n; i++) {
        if(i > a && dp[i - a] > 0 && dp[i] < dp[i - a] + 1) dp[i] = dp[i - a] + 1; 
        if(i > b && dp[i - b] > 0 && dp[i] < dp[i - b] + 1) dp[i] = dp[i - b] + 1; 
        if(i > c && dp[i - c] > 0 && dp[i] < dp[i - c] + 1) dp[i] = dp[i - c] + 1; 
    }

    printf("%d\n", dp[n]);
    return 0;
}