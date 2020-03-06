#include <bits/stdc++.h>
/* 
*  arr1, indice inicial do arr1, indice final do arr1
*  arr2, indice inicial do arr2, indice final do arr2
*  fnd = K-esima posicao
*/ 
int ans(int *arr1, int i1, int f1, int *arr2, int i2, int f2, int fnd) {
    if (i1 == f1) return arr2[fnd];
    if (i2 == f2) return arr1[fnd];
    int m1 = (i1+f1)/2;
    int m2 = (i2+f2)/2;
    if (m1 + m2 < fnd) {
        if (arr1[m1] > arr1[m2]) {
            return ans(arr1, i1, f1, arr2, i2+m2+1, f2, fnd-m2-1);
        }
        else {
            return ans(arr1, i1+m1+1, f1, arr2, i2, f2, fnd-m1-1);
        }
    }
    else {
        if (arr1[m1] > arr2[m2]) {
            return ans(arr1, i1, i1+m1, arr2, i2, f2, fnd);
        }
        else {
            return ans(arr1, i1, f1, arr2, i2, i2+m2, fnd);
        }
    }
}


int main() {
    
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8, 10};
    int n = 5;
    int fpos = 3;

    printf("%d\n", ans(arr1, 0, n, arr2, 0, n, fpos-1));
    
    return 0;
}