#include <bits/stdc++.h>

using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int N;
    cin >> N;
    while (N > 0) {
        int **matrix = (int**)malloc((N+1)*sizeof(int*));
        int **matrixsm = (int**)malloc((N+1)*sizeof(int*));
        int ***matrixaux = (int***)malloc((N+1)*sizeof(int**));
        int i, j;
        for (i = 0; i <= N; i++) {
            matrix[i] = (int*)malloc((N+1)*sizeof(int));
            matrixsm[i] = (int*)malloc((N+1)*sizeof(int));
            matrixaux[i] = (int**)malloc((N+1)*sizeof(int*));
        }
        for (i = 0; i <= N; i++) {
            for (j = 0; j <= N; j++) {
                matrixaux[i][j] = (int*)malloc(2*sizeof(int));
            }
        }
        for (i = 0; i <= N; i++) {
            for (j = 0; j <= N; j++) {
                matrix[i][j] = 0;
                matrixsm[i][j] = 0;
                matrixaux[i][j][0] = 0;
                matrixaux[i][j][0] = 0;
            }
        }
        for (i = 1; i <= N; i++) {
            for (j = 1; j <= i; j++) {
                cin >> matrix[i][j];
            }
        }
        for (i = 1; i <= N; i++) {
            for (j = 1; j <= i; j++) {
                matrixsm[i][j] += matrixsm[i-1][j] + matrixsm[i-1][j-1];
                if (i-2 >= 0) matrixsm[i][j] -= matrixsm[i-2][j-1];
                matrixsm[i][j] += matrix[i][j];
            }
        }
        int res = 0;
        for (i = 1; i <= N; i++) {
            for (j = i; j <= N; j++) {
                matrixaux[j][i][0] = matrixsm[j][i];
                matrixaux[j][i][0] = max(matrixaux[j][i][0], (matrixaux[j-1][i-1][1] + (matrixsm[j][i] - matrixsm[j-1][i-1])));
                res = max(res, matrixaux[j][i][0]);
            }
            matrixaux[N][i][1] = matrixaux[N][i][0];
            for (j = N-1; j >= i; j--) {
                matrixaux[j][i][1] = max(matrixaux[j+1][i][1], matrixaux[j][i][0]);
            } 
        }
        cout << res << "\n";
        cin >> N;
    }
}