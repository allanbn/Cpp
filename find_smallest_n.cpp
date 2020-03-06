#include <bits/stdc++.h>

int ans(int *arr1, int f1, int *arr2, int f2, int fnd) {
    int it1 = 0, it2 = 0, it3 = 0; 
    int *aux = (int*)malloc((f1+f2)*sizeof(int));
    while(it1 < f1 && it2 < f2) {
        if (arr1[it1] < arr2[it2]) aux[it3++] = arr1[it1++];
        else aux[it3++] = arr2[it2++];
    }
    while (it1 < f1) {
        aux[it3++] = arr1[it1++];
    }
    while (it2 < f2) {
        aux[it3++] = arr2[it2++]; 
    }
    return aux[fnd-1];
}

int main() {
    
    int fpos = 3;
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8, 10};
    int n = 5;
    
    printf("%d\n", ans(arr1, n, arr2, n, fpos));

    return 0;
}