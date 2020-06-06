#include <bits/stdc++.h>

#define MAX 10001

typedef struct {
    std::vector<int> adj;
}grafo;

grafo g[MAX]; // indice == vertice
int visited[MAX];

int DFS(int v) {
    int i, verif;
    visited[v] = 1;
    for (i = 0; i < g[v].adj.size(); i++) {
        if (visited[g[v].adj[i]] == 0) {
            verif = DFS(g[v].adj[i]);
            if (verif) return 1;
        }
        else if (visited[g[v].adj[i]] == 1) return 1;
    }
    visited[v] = 2;
    return 0;
}

int main() {
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        int n, m, a, b;
        memset(visited, 0, MAX*sizeof(int));
        scanf("%d %d", &n, &m);
        while(m--) {
            scanf("%d %d", &a, &b);
            g[a-1].adj.push_back(b-1);
        }
        int i, verif = 0;
        for (i = 0; i < n; i++) {
            if (visited[i] == 0) {
               verif = DFS(i);
            } 
            if (verif) break; 
        }
        if (verif) printf("SIM\n");
        else printf("NAO\n");
        for (i = 0; i < n; i++) {
            g[i].adj.clear();
        }
    }
    return 0;
}