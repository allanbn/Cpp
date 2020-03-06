#include <bits/stdc++.h>

/*Complexidade: O(nlogn)*/

using namespace std;

int bb(int *arr, int i, int f, int fnd) {
    int _max = arr[f-1];
    int _min = arr[i];
    while (_min <= _max){
        int m = _min + (_max-_min)/2; // elemento do meio
        int cMenores = 0, cIguais = 0;
        int j;
        for (j = 0; j < f; j++) {
            if (arr[j] < m) cMenores++;
            else if (arr[j] == m) cIguais++;
            if (cMenores >= fnd) break;
        }

        if ((cMenores < fnd) && ((cMenores+cIguais) >= fnd)) return m;
        else if (cMenores >= fnd) _max = m - 1;
        else _min = m + 1;
    }
}

int ans(int *arr1, int i1, int f1, int *arr2, int i2, int f2, int fnd) {
    int x = bb(arr1, i1, f1, fnd);
    int y = bb(arr2, i2, f2, fnd);
    return min(x, y); 
}

int main() {
    
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8, 10};
    int n = 5;
    int fpos = 3;

    printf("%d\n", ans(arr1, 0, n, arr2, 0, n, fpos-1));
    
    return 0;
}







