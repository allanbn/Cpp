#include <bits/stdc++.h>

void printArray(int *arr, int n);
void preencheArray(int *arr, int n);
void copyArray(int *dst, int *src, int n);
void swap(int *arr, int ia, int ib);
// void insertionSort(int *arr, int f);
void mergeSort(int *arr, int i, int f);
void timInsertion(int *arr, int i, int f);
void Merge(int *arr, int i, int f);
void timSort(int *arr, int i, int f);
int checkSort(int *arr, int f);

int main() {
    int n;
    srand(time(NULL));
    printf("Insira o tamanho do vetor:\n");
    scanf("%d", &n);
    int *v1 = (int*)malloc(n*sizeof(int));
    int *v2 = (int*)malloc(n*sizeof(int));
    int *v3 = (int*)malloc(n*sizeof(int));
    preencheArray(v1, n);
    copyArray(v2, v1, n);
    copyArray(v3, v1, n);
    // printArray(v, n);
    clock_t ticks[2];
    // ticks[0] = clock();
    // insertionSort(v1, n);
    // ticks[1] = clock();
    // printArray(v1, n);
    // double t1 = (double)(ticks[1] - ticks[0]) / CLOCKS_PER_SEC;
    ticks[0] = clock();
    mergeSort(v2, 0, n);
    ticks[1] = clock();
    // printArray(v2, n);
    double t2 = (double)(ticks[1] - ticks[0]) / CLOCKS_PER_SEC;
    ticks[0] = clock();
    timSort(v3, 0, n);
    ticks[1] = clock();
    // printArray(v3, n);
    double t3 = (double)(ticks[1] - ticks[0]) / CLOCKS_PER_SEC;
    // printf("Insertion Sort time: %lfs\n", t1);
    printf("Merge Sort time: %lfs\n", t2);
    printf("Tim Sort time: %lfs\n\n", t3);
    // printf("Check Insertion Sort: %d\n", checkSort(v1, n));
    printf("Check Merge Sort: %d\n", checkSort(v2, n));
    printf("Check Tim Sort: %d\n", checkSort(v3, n));
    return 0;
}

void printArray(int *arr, int n) {
    int i;
    printf("[");
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i + 1 < n) printf(" ");
    }
    printf("]\n");
}

void preencheArray(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = (rand()%101)-50;
    }
}

void copyArray(int *dst, int *src, int n) {
    int i;
    for (i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

void swap(int *arr, int ia, int ib) {
    int aux = arr[ia];
    arr[ia] = arr[ib];
    arr[ib] = aux;
}

// void insertionSort(int *arr, int f) {
//     int i;
//     for (i = 1; i < f; i++) {
//         int at = arr[i];
//         int j = i-1;
//         while (j >= 0 && arr[j] > at) {
//             arr[j+1] = arr[j];
//             j--;
//         }
//         arr[j+1] = at;
//     }
// }

void timInsertion(int *arr, int i, int f) {
    int j;
    for (j = i+1; j <= f; j++) {
        int at = arr[j];
        int x = j-1;
        while (x >= i && arr[x] > at) {
            arr[x+1] = arr[x];
            x--;
        }
        arr[x+1] = at;
    } 
}

void Merge(int *arr, int i, int f) {
    int m = (i+f)/2;
    int it1 = i, it2 = m+1;
    int *arraux = (int*)malloc((f-i+1)*sizeof(int));
    int itaux = 0;
    
    while (it1 <= m && it2 <= f) {
        if (arr[it1] < arr[it2]) arraux[itaux++] = arr[it1++];
        else arraux[itaux++] = arr[it2++];
    }
    
    while (it1 <= m) arraux[itaux++] = arr[it1++];
    while (it2 <= f) arraux[itaux++] = arr[it2++];

    int j;
    for (j = i; j <= f; j++) {
        arr[j] = arraux[j-i];
    }
}

void mergeSort(int *arr, int i, int f) {
    if (i == f) return;
    else if ((f-i) == 1 && arr[i] > arr[f]) swap(arr, i, f);
    else {
        int m = (i+f)/2;
        mergeSort(arr, i, m);
        mergeSort(arr, m+1, f);
        Merge(arr, i, f);
    }
}

void timSort(int *arr, int i, int f) {
    if (i == f) return;
    else if ((f-i) == 1 && arr[i] > arr[f]) swap(arr, i, f);
    else if (35 <= (f-i) && (f-i) <= 45) timInsertion(arr, i, f);
    else {
        int m = (i+f)/2;
        timSort(arr, i, m);
        timSort(arr, m+1, f);
        Merge(arr, i, f);
    }
}

int checkSort(int *arr, int f) {
    int i;
    for (i = 0; i < f-1; i++) {
        if (arr[i] > arr[i+1]) return 0;
    }
    return 1;
}
