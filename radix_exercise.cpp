#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

#define TAM 100000

using namespace std;

//VETORES USADOS NO COUNTING ALOCADOS GLOBALMENTE
int *c = (int*)malloc(27*sizeof(int));
char **b = (char**)malloc(TAM*sizeof(char*));

//função de comparação usada no qsort
int compare(const void *a, const void *b) {
    char *va = (char*) a;
    char *vb = (char*) b;
    return strcmp(va, vb);
}

void countingsort(char A[TAM][4], int n, int k, int d) {

    memset(c, 0, (k+1)*sizeof(int)); //zera o vetor c
    int i;
    //IMPLEMENTE O RESTO DO COUNTING SORT
    //OBS: pode supor que a entrada só contém letras minúsculas e as strings tem tamanho 4 (três caracteres e o \0 do final)
    //OBS2: O vetor C tem tamanho 27 para esse cenário, uma para cada letra. Para obter o índice do vetor C use a expressão A[i][j] - 'a'
    for (i = 0; i < n; i++) c[A[i][d] - 'a']++;

    for (i = 1; i < k; i++) c[i] += c[i - 1];

    for (i = n-1; i >= 0; i--) strcpy(b[--c[A[i][d] - 'a']], A[i]);

    for (i = 0; i < n; i++) strcpy(A[i], b[i]);
}

int main() {
    char nomes[TAM][4];
    char nomescopy[TAM][4];
    srand(time(NULL));

    clock_t ticks[2];

    //gera strings aleatórias
    for (int i = 0; i < TAM; i++) {
        char stral[4];
        for(int k = 0; k < 3; k++) stral[k] = (rand()%26) + 'a';
        stral[3] = '\0';
        strcpy(nomes[i], stral);
    }

    //faz uma cópia do array de string para usar no qsort
    for(int i = 0; i < TAM; i++) strcpy(nomescopy[i], nomes[i]);

    ticks[0] = clock();
    //executa o radix sort
    for(int i = 0; i < TAM; i++) b[i] = (char*) malloc(4*sizeof(char));
    for(int d = 2; d >= 0; d--) {
        countingsort(nomes, TAM, 27, d);
    }
    ticks[1] = clock();
    double tempo1 = (double)(ticks[1] - ticks[0]) / CLOCKS_PER_SEC;

    ticks[0] = clock();
    //executa o quicksort
    qsort(nomescopy, TAM, 4*sizeof(char), compare);
    ticks[1] = clock();
    double tempo2 = (double)(ticks[1] - ticks[0])/ CLOCKS_PER_SEC;

    //verifica se os resultados das ordenações foram iguais
    for(int i = 0; i < TAM; i++) {
        cout << nomes[i] << "  " << nomescopy[i] << " - " << strcmp(nomes[i], nomescopy[i]) << endl;
    }

    //mostra o tempo de execução dos algoritmos
    printf("%lf %lf\n",tempo1, tempo2);

    return 0;
}
