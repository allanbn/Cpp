#include <iostream>

#define INF 0x3F3F3F3F

using namespace std;

typedef struct dadoverif {
    int d;
    bool v;
}TDado;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int monta_res(int** m, char* arr, TDado** dados, int i, int j) {
    if (j == 0) return 1;
    if (i == 0) {
        if (m[j][arr[i] - 'a'] == 0) return 1;
        else return INF;
    }
    if (m[j][arr[i]-'a'] == 0) return 1;
    if (dados[i][j].v) return dados[i][j].d;
    dados[i][j].d = INF; 
    dados[i][j].d = min(dados[i][j].d, monta_res(m, arr, dados, i-1, j));
    dados[i][j].d = min(dados[i][j].d, 1 + monta_res(m, arr, dados, i-1, m[j][(arr[i] - 'a')] - 1));
    dados[i][j].v = true;
    return dados[i][j].d;
}

int main() {
    int N, M;
    cin >> N >> M;
    int** in = (int**)malloc((M+1)*sizeof(int*));
    TDado** dados = (TDado**)malloc((N+1)*sizeof(TDado*));
    int i;
    for (i = 0; i <= N; i++) {
        dados[i] = (TDado*)malloc((M+1)*sizeof(TDado));
    }
    int j;
    for (i = 0; i <= N; i++) {
        for (j = 0; j <= M; j++) {
            dados[i][j].v = false; 
        }
    }
    for (i = 0; i <= M; i++) in[i] = (int*)malloc(27*sizeof(int));
    char str1[N+1], str2[M+1];
    cin >> str1 >> str2; 
    for (i = 1; i <= M; i++) {
        for (j = 0; j < 26; j++) {
            in[i][j] = in[i-1][j];
            if (j == str2[i-1] - 'a') in[i][j] = i;
        }
    }
    printf("%d\n", monta_res(in, str1, dados, N-1, M));
    return 0;
}