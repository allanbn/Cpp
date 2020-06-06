#include <bits/stdc++.h>

char backtracking(char** m, int** maux, int x, int y,
                  int sx, int sy, int i, int f) {
    if (maux[x][y] == 0 && (x < i && y < f)) {
        char verif;
        maux[x][y] = 1;
        if (m[x][y] == '*') return '*';
        else {
            if (m[x][y] == '>') {
                sx = 0; sy = 1;
                verif = backtracking(m, maux, x+sx, y+sy, sx, sy, i, f);
                if (verif == '!') return '!';
                else if (verif == '*') return '*';
            }
            else if (m[x][y] == '<') {
                sx = 0; sy = -1;
                verif = backtracking(m, maux, x+sx, y+sy, sx, sy, i, f);
                if (verif == '!') return '!';
                else if (verif == '*') return '*';
            }
            else if (m[x][y] == '^') {
                sx = -1; sy = 0;
                verif = backtracking(m, maux, x+sx, y+sy, sx, sy, i, f);
                if (verif == '!') return '!';
                else if (verif == '*') return '*';
            }
            else if (m[x][y] == 'v') {
                sx = 1; sy = 0;
                verif = backtracking(m, maux, x+sx, y+sy, sx, sy, i, f);
                if (verif == '!') return '!';
                else if (verif == '*') return '*';
            }
            else {
                verif = backtracking(m, maux, x+sx, y+sy, sx, sy, i, f);
                if (verif == '!') return '!';
                else if (verif == '*') return '*';
            }
        }
    }
    return '!';
}

int main() {
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    char **matrix = (char**)malloc(y*sizeof(char*));
    int **auxMatrix = (int**)malloc(y*sizeof(int*));
    int i, j;
    for (i = 0; i < y; i++) {
        matrix[i] = (char*)malloc(x*sizeof(char));
        auxMatrix[i] = (int*)malloc(x*sizeof(int));
    }
    for (i = 0; i < y; i++) {
        for (j = 0; j < x; j++) {
            auxMatrix[i][j] = 0;
        }
    }
    for (i = 0; i < y; i++) {
        getchar();
        scanf("%s", matrix[i]);
    }
    char verif = backtracking(matrix, auxMatrix, 0, 0, 0, 0, y, x);
    printf("%c\n", verif);
}