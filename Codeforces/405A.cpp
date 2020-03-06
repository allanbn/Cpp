#include <bits/stdc++.h>

using namespace std;

int *b;
int *c;

void csort(int *arr, int n) {
    b = (int*)malloc((n+1)*sizeof(int));
    c = (int*)calloc(101, sizeof(int));

    int i;

    for (i = 0; i < n; i++) c[arr[i]]++;

    for (i = 1; i < 101; i++) c[i] += c[i-1];

    for (i = n-1; i >= 0; i--) b[--c[arr[i]]] = arr[i];

    for (i = 0; i < n; i++) arr[i] = b[i];
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    int i;
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    csort(arr, n);
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}