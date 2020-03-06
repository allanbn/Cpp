#include <bits/stdc++.h>

void preencheArray(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = (rand()%101)-50;
    }
}

int ans_brute(int *arr, int i, int n) {
    int m = 0, j, k;
    for (j = i; j <= n; j++) {
        int sm_k = 0;
        for (k = j; k <= n; k++) {
            sm_k += arr[k];
            if (sm_k > m) m = sm_k;
        }
    }
    return m;
}

int max(int a, int b) {
    return (a > b) ? a:b;
}

int compare(int a, int b, int c) {
    return max(max(a, b), c);
}

int somaMeio(int const* arr, int i, int f) {
    int m = (i+f)/2;
    int s1 = 0;
    int s2 = 0;
    int k;
    int somaaux1 = 0;
    int somaaux2 = 0;
    for (k = m; k >= i; k--) {
        somaaux1 += arr[k];
        if (somaaux1 > s1) s1 = somaaux1;
    }
    for (k = m + 1; k <= f; k++) {
        somaaux2 += arr[k];
        if (somaaux2 > s2 ) s2 = somaaux2;
    }
    return (s1 + s2);
}

int ans_rec(int* arr, int i, int f) {
    if (i == f) {
        return arr[i];
    }
    int m = (i+f)/2;
    int som1 = ans_rec(arr, i, m);
    int som2 = ans_rec(arr, m+1, f);
    int sm = somaMeio(arr, i, f);
    return compare(som1, som2, sm);
}

int ans_mx(int *arr, int i, int f) {
    if (i == f) {
        return arr[i];
    }
    else if (f - i < 20) return ans_brute(arr, i, f);
    int m = (i+f)/2;
    int som1 = ans_mx(arr, i, m);
    int som2 = ans_mx(arr, m+1, f);
    int sm = somaMeio(arr, i, f);
    return compare(som1, som2, sm);
}

int main() {
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    int *v = (int*)malloc(n*sizeof(int));
    preencheArray(v, n);
    clock_t ticks[2];
    ticks[0] = clock();
    printf("%d\n", ans_brute(v, 0, n-1));
    ticks[1] = clock();
    double t1 = (double)(ticks[1] - ticks[0]) / CLOCKS_PER_SEC;
    ticks[0] = clock();
    printf("%d\n", ans_rec(v, 0, n-1));
    ticks[1] = clock();
    double t2 = (double)(ticks[1] - ticks[0]) / CLOCKS_PER_SEC;
    ticks[0] = clock();
    printf("%d\n", ans_mx(v, 0, n-1));
    ticks[1] = clock();
    double t3 = (double)(ticks[1] - ticks[0]) / CLOCKS_PER_SEC;
    printf("Brute force time: %lfs\n", t1);
    printf("Recurssive time: %lfs\n", t2);
    printf("Mixed time: %lfs\n", t3);
    return 0;
}

