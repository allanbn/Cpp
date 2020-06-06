#include <bits/stdc++.h>
// 0 do, 1 do#, 2 re, 3 re#, 4 mi
// 5 fa, 6 fa#, 7 sol, 8 sol#, 9 lá
// 10 la#, 11 si
using namespace std;

int main() {
    int passos[] = {0, 2, 4, 5, 7, 9, 11, 12};
    string chords[] = {"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si"};
    int n;
    scanf("%d", &n);
    int arr[n];
    memset(arr, 0, n*sizeof(int));
    int i, v;
    for (i = 0; i < n; i++) {
        scanf("%d", &v);
        arr[i] = ((v - 1) % 12);
    }
    int barr[12];
    int verif = 0;
    for (i = 0; i < 12; i++) {
        memset(barr, 0, 12*sizeof(int));
        int j;
        for (j = 0; j < 7; j++) barr[(i+passos[j]) % 12] = 1;
        int ok = 1;
        for (j = 0; j < n; j++) {
            if (ok == 1 && barr[arr[j]] == 1) ok = 1;
            else ok = 0;
        }
        if (ok == 1) {
            cout << chords[i] << '\n';
            verif = 1;
            break;
        }
    }
    if (verif == 0) printf("desafinado\n");
    return 0;
}