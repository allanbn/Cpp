#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*) a - *(int*) b);
} 

int main() {
    int n;
    scanf("%d", &n);
    int arr[n+1];
    int arr_i = 0, soma = 0, res = 0;
    int m = INT_MIN;
    int aux;
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &aux);
        if ((aux > 0) && (aux%2 == 1)) {
            arr[arr_i++] = aux;
            res += aux;
        }
        else if ((aux > 0) && (aux%2 == 0)) soma += aux;
        else {
            if (abs(aux)%2 == 1 && aux > m) m = aux;
        }
    }
    if (!arr_i) printf("%d\n", (soma + m));
    else if (arr_i%2 == 1) printf("%d\n", (res + soma));
    else {
        qsort(arr, arr_i, sizeof(int), cmp);
        if (m == INT_MIN) printf("%d\n", (res + soma - arr[0]));
        else {
            int resaux = fmax((res + soma - arr[0]), (res + soma + m));
            printf("%d\n", resaux);
        }
    }
    return 0;
}