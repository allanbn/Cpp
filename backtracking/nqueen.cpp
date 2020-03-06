#include <iostream>
#include <cstring>

#define max 8

using namespace std;

bool free_position(int tab[max][max], int i, int k, int n) {
    //verifica linha
    for(int a = k-1; a >= 0; a--) {
        if(tab[i][a]) return false;
    }
    //verifica diagonal para esquerda para cima
    for(int a = i-1,b = k-1; a >= 0 &&  b >= 0 ; a--, b--) {
        if(tab[a][b]) return false;
    }
    //verifica diagonal para esquerda para baixo
    for(int a = i+1,b = k-1; a < n &&  b >= 0 ; a++, b--) {
        if(tab[a][b]) return false;
    }
    //verifica diagonal para direita para cima
    for(int a = i-1,b = k+1; a >= 0 &&  b < n ; a--, b++) {
        if(tab[a][b]) return false;
    }
    //verifica diagonal para direita para baixo
    for(int a = i+1,b = k+1; a < n &&  b < n ; a++, b++) {
        if(tab[a][b]) return false;
    }
    return true;
}

void print_solution(int tab[max][max], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool backtracking(int tab[max][max], int k, int n) {
    if(k == n) {
        print_solution(tab,n);
        return true;
    }
    else {
        for(int i = 0; i < n; i++) {
            if(free_position(tab,i,k,n)) {
                tab[i][k] = 1;
                k++;
                backtracking(tab,k,n);
                k--;
                tab[i][k] = 0;
                //backtracking(tab,k,n);
            }   
        } 
    }
    return false;
}

int main() {
    int tab[max][max];
    int n;
    cin >> n;
    memset(tab,0,max*max*sizeof(int));
    //for(int i = 0; i < n; i++)
    backtracking(tab,0,n);
    return 0;
}
