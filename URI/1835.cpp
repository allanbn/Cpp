#include <bits/stdc++.h>

#define MAX 101

int matrix[MAX][MAX]; // grafo
int visited[MAX];

void DFS(int v, int n) {
    int i;
    visited[v] = 1;
    for (i = 0; i < n; i++) {
        if (matrix[v][i] == 1 && visited[i] == 0) {
            DFS(i, n);
        }
    }
}

int main() {
    int cases, count = 0;
    scanf("%d", &cases);
    while(count++ < cases) {
        int n, m, x, y;
        memset(matrix, 0, MAX*MAX*sizeof(int));
        memset(visited, 0, MAX*sizeof(int));
        scanf("%d", &n);
        scanf("%d", &m);
        while(m--) {
            scanf("%d %d", &x, &y);
            matrix[x-1][y-1] = 1;
            matrix[y-1][x-1] = 1;
        }
        int verif = -1;
        int i;
        for (i = 0; i < n; i++) {
            if (visited[i] == 0) {
                DFS(i, n);
                verif++;
            }
        }
        if (verif == 0) printf("Caso #%d: a promessa foi cumprida\n", count);
        else printf("Caso #%d: ainda falta(m) %d estrada(s)\n", count, verif);
    }
    return 0;
}