#include <bits/stdc++.h>

#define MAX 49 // 7x7

int matrix[MAX+1][MAX+1];
int visited[MAX+1];

int DFS(int v, int n) {
    int i, count = 0;
    visited[v] = 1;
    for (i = 0; i < n; i++) {
        if (matrix[v][i] == 1 && visited[i] == 0) {
            count += DFS(i, n) + 1;
        }
    }
    return count;
}

int main() {
    int cases, st, v, a;
    scanf("%d", &cases);
    while(cases--) {
        scanf("%d", &st);
        scanf("%d %d", &v, &a);
        memset(visited, 0, (MAX+1)*sizeof(int));
        memset(matrix, 0, (MAX+1)*(MAX+1)*sizeof(int));
        while(a--) {
            int y, z;
            scanf("%d %d", &y, &z);
            matrix[y][z] = 1;
            matrix[z][y] = 1;
        }
        int count = DFS(st, v);
        count += count;
        printf("%d\n", count);
    }  
    return 0;
}