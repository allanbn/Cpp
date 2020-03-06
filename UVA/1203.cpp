#include <bits/stdc++.h>

using namespace std;

int main() {
    // MIN_HEAP
    priority_queue<pair<int, pair<int, int>>, // tipo guardado
            vector<pair<int, pair<int, int>>>, // estrutura que esta guardando pair funciona como a struct Argus
			greater<pair<int, pair<int, int>>>> pq; //comparador pra ordernar a pq em min heap
    char in[21];
    int ID, period;
    while (scanf("%s", in), in[0] != '#') {
        scanf("%d %d", &ID, &period);
        pq.push(pair<int, pair<int, int>>(period, pair<int, int>(ID, period)));
    }
    int K;
    scanf("%d", &K);
    while (K--) {
        pair<int, pair<int, int>> aux = pq.top();
        pq.pop();
        printf("%d\n", aux.second.first);
        aux.first += aux.second.second;
        pq.push(aux);
    }
}