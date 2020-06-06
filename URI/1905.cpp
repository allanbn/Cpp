#include <bits/stdc++.h>

#define MAX 5

using namespace std;

bool backtracking(int m[MAX][MAX], int maux[MAX][MAX], int i, int j);
bool verifica(int m[MAX][MAX], int maux[MAX][MAX], int i, int j);

int main() {
    int matrix[MAX][MAX];
    int matrixaux[MAX][MAX];
    int cases, i, j;
    scanf("%d", &cases);
    while(cases--) {
        memset(matrix, 0, MAX*MAX*sizeof(int));
        memset(matrixaux, 0, MAX*MAX*sizeof(int));
        for (i = 0; i < MAX; i++) {
            for (j = 0; j < MAX; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
        if (backtracking(matrix, matrixaux, 0, 0)) printf("COPS\n");
        else printf("ROBBERS\n");
    }
    return 0;
}

bool backtracking(int m[MAX][MAX], int maux[MAX][MAX], int i, int j) {
    maux[i][j] = 1;
    if ((i == MAX-1) && (j == MAX-1)) return true;
    else {
        if (verifica(m, maux, i, j)) return true;
    }
    return false;
}

bool verifica(int m[MAX][MAX], int maux[MAX][MAX], int i, int j) {
    bool ret = false;
    if ((i > 0) && (maux[i-1][j] == 0) && (m[i-1][j] == 0)) {
        ret = backtracking(m, maux, i-1, j);
        if (ret) return ret;
    }
    if ((i < MAX-1) && (maux[i+1][j] == 0) && (m[i+1][j] == 0)) {
        ret = backtracking(m, maux, i+1, j);
        if (ret) return ret;
    }
    if ((j > 0) && (maux[i][j-1] == 0) && (m[i][j-1] == 0)) {
        ret = backtracking(m, maux, i, j-1);
        if (ret) return ret;
    } 
    if ((j < MAX-1) && (maux[i][j+1] == 0) && (m[i][j+1] == 0)) {
        ret = backtracking(m, maux, i, j+1);
        if (ret) return ret;
    }
    return ret;
}