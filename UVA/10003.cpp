#include <bits/stdc++.h>

using namespace std;

int ans(int n, int *arr) {
    int dp[52][52];
    memset(dp, 0, sizeof(dp));
    int i;
    for (i = 1; i <= n; i++) {
        int j;
        for (j = i-1; j >= 0; j--) {
            if (j+1 == i) dp[j][i] = 0;
            else {
                dp[j][i] = INT_MAX;
                int k;                
                for (k = j+1; k < i; k++) {
                    dp[j][i] = min(dp[j][k]+dp[k][i], dp[j][i]);		
                }
                dp[j][i] += arr[i] - arr[j];
            }
        }
    }
    return dp[0][n];
}

int main() {
    int l, n, arr[52];
    arr[0] = 0;
    while (scanf("%d", &l), l != 0) {
        scanf("%d", &n);
        int i;
        for (i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
        }
	    arr[++n] = l;
        printf("The minimum cutting is %d.\n", ans(n, arr));
    }
    
    return 0;
}
