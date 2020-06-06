#include <bits/stdc++.h>

// problema de dijkstra

#define MAX 500
#define INF 999999

typedef struct {
    int qVerts;
    int qArst;
    int matrix[MAX][MAX]; // guardar os pesos do caminho x->y
}grafo;

grafo g;

void dijkstra (int I, int F){
    int W = I;
    int BETA[g.qVerts];
    int PHI[g.qVerts];
    int PI[g.qVerts];
    memset (BETA, INF, g.qVerts*sizeof(int));
    memset (PHI, 0, g.qVerts*sizeof(int));
    memset (PI, -1, g.qVerts*sizeof(int));
    BETA[W] = 0;
    while (PHI[W] != 1) {
        PHI[W] = 1;
        for (int i = 0; i < g.qVerts; i++) {
            if ((W != i) && (g.matrix[W][i] < INF) && (PHI[i] == 0) && (BETA[i] > BETA[W] + g.matrix[W][i])) {
                BETA[i] = BETA[W] + g.matrix[W][i];
                PI[i] = W;
            }
        }
        int MIN = INF;
        int index_min = -1;
        for (int i = 0; i < g.qVerts; i++) {
            if ((W != i) && (BETA[i] < INF) && (BETA[i] < MIN) && (PHI[i] == 0)) {
                MIN = BETA[i];
                index_min = i;
            }
        }
        if (index_min != -1) {
            W = index_min;
        }
    }
    if (BETA[F] < INF) printf("%d\n", BETA[F]);
    else printf("Nao e possivel entregar a carta\n");
}
int main() {
    int n, e, x, y, h, k, o, d;
    while (1) {
        scanf("%d %d", &n, &e);
        if (n == 0 && e == 0) break;
//        memset(g.matrix, INF, sizeof(g.matrix)); // caminhos com peso infinito... MEMSET N FUNCIONAVA GRR
        g.qVerts = n;
        g.qArst = e;
        int i, j;
        for (i = 0; i < g.qVerts; i++) {
            for (j = 0; j < g.qVerts; j++) {
                g.matrix[i][j] = INF;
            }
        }
        while(e--) {
            scanf("%d %d %d", &x, &y, &h); // aresta x->y + peso
            g.matrix[x-1][y-1] = h;
        }
        for (i = 0; i < g.qVerts; i++) {
            for (j = 0; j < g.qVerts; j++) {
                if (g.matrix[i][j] != INF && g.matrix[j][i] != INF) {
                    g.matrix[i][j] = 0;
                    g.matrix[j][i] = 0;
                }
            }
        }
        scanf("%d", &k);
        while(k--) {
            scanf("%d %d", &o, &d); // origem->destino
            dijkstra(o-1, d-1);
        }
        printf("\n");
    }
    return 0;
}