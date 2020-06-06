#include <bits/stdc++.h>

struct corte {
    int t;
    int v;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

void menosum_matriz(int** m, int n, int t) {
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= t; j++) {
            m[i][j] = -1;
        }
    }
}
            //matriz, toras, casos, casos MAX, Comprimento
int pipe_cut(int** m, corte* c, int n, int N, int T) {
    if (n == N) return 0;
    if (T == 0) return 0;
    if (T < 0) return INT32_MIN;
    if (m[n][T] == -1) {
        m[n][T] = max(pipe_cut(m, c, n+1, N, T), (c[n].v + pipe_cut(m, c, n, N, T-c[n].t)));
    }
    return m[n][T];
}

int main() {
    int N, T;
    while ( scanf("%d %d", &N, &T) != EOF ) {
        corte arr[N+1];
        int **arr1 = (int**)malloc((N+1)*sizeof(int*));
        int i;
        for (i = 0; i <= N; i++) arr1[i] = (int*)malloc((T+1)*sizeof(int));
        menosum_matriz(arr1, N, T);
        for (i = 0; i <= N; i++) scanf("%d %d", &arr[i].t, &arr[i].v);
        printf("%d\n", pipe_cut(arr1, arr, 0, N, T));
    }
    return 0;
}