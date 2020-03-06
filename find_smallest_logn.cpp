#include <bits/stdc++.h>

using namespace std;

// dividir os 2 arrays por fnd/2 e recursar

int ans(int *arr1, int i1, int f1, int *arr2, int i2, int f2, int fnd) {
    if ((f1-i1) == 0) return arr2[i2+fnd-1];
    if ((f2-i2) == 0) return arr1[i1+fnd-1];
    if (fnd == 1) return min(arr1[i1+fnd-1], arr2[i2+fnd-1]);
    int div_fnd = fnd/2;
    int index1 = min(f1, div_fnd);
    int index2 = min(f2, div_fnd);
    if (arr1[i1+index1-1] > arr2[i2+index2-1]) {
        return ans(arr1, i1, f1, arr2, i2+index2, f2-index2, fnd-index2);
    }
    else {
        return ans(arr1, i1+index1, f1-index1, arr2, i2, f2, fnd-index1);
    }
}


int main() {
    
    int fpos = 13;
    // int arr1[] = {1, 2, 5, 7, 9};
    // int arr2[] = {3, 4, 6, 8, 10};
    int arr1[] = {1, 4, 8, 10, 15, 20, 23, 30, 99};  
    int arr2[] = {2, 3, 6, 7, 9, 11, 12, 13, 14};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]); 
    // int n = 5;
    if (fnd <= (n+m)) {
        printf("%d\n", ans(arr1, 0, n, arr2, 0, m, fpos));
    }
    

    return 0;
}