#include <bits/stdc++.h>

#define MAX 255
#define INF 999999

typedef struct {
    int qVerts;
    int qArst;
    int matrix[MAX][MAX]; // guardar os pesos do caminho x->y
}grafo;

grafo g;

std::queue<int> q;
int dijkstra(int I, int F){
    int W = I;
    int BETA[g.qVerts];
    int PHI[g.qVerts];
    int PI[g.qVerts];
    memset(BETA, INF, g.qVerts*sizeof(int));
    memset(PHI, 0, g.qVerts*sizeof(int));
    memset(PI, -1, g.qVerts*sizeof(int));
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
    return BETA[F];
}

// simplifiquei o trambalho acima porem nao usei
// int dijkstra2(int I, int F){
//  int BETA[g.qVerts];
//  memset(BETA, INF, g.qVerts*sizeof(int));
// 	BETA[I] = 0;
// 	q.push(I);
// 	while(!q.empty()){
// 		int i = q.front();
// 		q.pop();
//         int j;
// 		for(j = 0; j < g.qVerts; j++){
// 			if(g.matrix[i][j] != INF && BETA[j] > BETA[i] + g.matrix[i][j]){
// 				BETA[j] = BETA[i] + g.matrix[i][j];
// 				q.push(j);
// 			}
// 		}
// 	}
// 	return BETA[F];
// }


int main() {
    int N, M, C, K;
    while (1) {
        scanf("%d %d %d %d", &N, &M, &C, &K);
        // nr de cidades, nr de estradas, nr cidades na rota (C) e
        // cidade que consertou o veiculo
        if (N == 0 && M == 0 && C == 0 && K == 0) break;
        g.qVerts = N;
        g.qArst = M;
        int i, j;
        for (i = 0; i < g.qVerts; i++) {
            for (j = 0; j < g.qVerts; j++) {
                g.matrix[i][j] = INF;
            }
        }
        while(M--) {
            int x, y, h;
            scanf("%d %d %d", &x, &y, &h); // aresta x->y + peso
            if ((x >= C && y >= C) || (x < C && y < C && abs(x-y) == 1)){
                g.matrix[x][y] = h;
                g.matrix[y][x] = h;
            }
            if (x >= C && y < C) {
                g.matrix[x][y] = h;
            }
            if (x < C && y >= C){
                g.matrix[y][x] = h;
            }
        }
        printf("%d\n", dijkstra(K, C-1));
    }
    return 0;
}