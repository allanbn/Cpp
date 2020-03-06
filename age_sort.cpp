#include <iostream>
#include <cstring>

void printArray(int* arr, int f) {
    int j;
    for (j = 0; j < f; j++) {
        printf("%d", arr[j]);
        if (j + 1 < f) printf(" ");
    }
    printf("\n");
}

// void merge(int *v, int i, int f) {
//     int m = (i+f)/2;
//     int it1 = i, it2 = m+1;
//     int *vaux = (int*)malloc((f-i+1)*sizeof(int));
//     int itaux = 0;
        
//     while(it1 <= m && it2 <= f) {
//         if(v[it1] < v[it2]) {
//             vaux[itaux] = v[it1];
//             it1++;
//         }
//         else {
//             vaux[itaux] = v[it2];
//             it2++;
//         }
//         itaux++;
//     }
//     while (it1 <= m) {      
//         vaux[itaux] = v[it1];
//         it1++;
//         itaux++;
//     }
//     while (it2 <= f) {       
//         vaux[itaux] = v[it2];
//         it2++;
//         itaux++;
//     }
//     int a;
//     for(a = i; a <= f; a++) { 
//         v[a] = vaux[a-i];
//     }
// }

// void mergeSort(int *v, int i, int f) {
//     int m;
//     if(i == f) {
//         return;
//     }
//     else if((f-i) == 1) { 
//         if(v[f] < v[i]) {
//             int aux = v[i];
//             v[i] = v[f];
//             v[f] = aux;
//         }
//     }
//     else {
//         m = (i+f)/2;
//         mergeSort(v,i,m);
//         mergeSort(v,m+1,f);
//         merge(v,i,f);
//     }
// }

void countingsort(int* A, int n, int k) {
    int *c = (int*)malloc((100+1)*sizeof(int));
    int *res = (int*)malloc(100*sizeof(int));
    memset(c, 0, (100+1)*sizeof(int)); // zera o vetor c
    int i;
    for (i = 0; i < n; i++) {
        c[A[i]]++;
    }
    for (i = 1; i < k; i++) {
        c[i] += c[i - 1];
    }
    for (i = n-1; i >= 0; i--) {
        res[--c[A[i]]] =  A[i];
    }
    for (i = 0; i < n; i++) {
        A[i] = res[i];
    }
}

int main() {
    int n, i, k, id;
    int maiorId = INT32_MIN;
    scanf("%d", &n);
    while (n != 0) {
        int arr[n];
        i = 0;
        k = 0;
        while (k < n) {
            scanf("%d", &id);
            if ((0 < id) && (id < 100)) arr[i++] = id;
            if (id > maiorId) maiorId = id;
            k++;
        }
        // mergeSort(arr, 0, i-1);
        countingsort(arr, n, maiorId);
        printArray(arr, i);
        scanf("%d", &n);
    }
    return 0;
}