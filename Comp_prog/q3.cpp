#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int qnt;
    int peso;
}galho;

int arr[1005][1005];
galho tmp[105];

int main() {
    int g;
    int c = 0;
    cin >> g;
    while (g--) {
        memset(arr, 0, sizeof(arr));
        int p;
        cin >> p;
        int w;
        cin >> w;
        int i;
        for (i = 1; i <= p; i++) {
           cin >> tmp[i].qnt >> tmp[i].peso;
        }
        int x, y;
        for (x = 1; x <= w; x++) { // peso
            for (y = 1; y <= p; y++) { // item
                if (tmp[y].peso <= x) {
                    arr[x][y] = max(arr[x][y-1], (tmp[y].qnt + arr[x-tmp[y].peso][y-1]));
                }
                else {
                    arr[x][y] = arr[x][y-1];
                }
            }
        }
        // for (i = 1; i <= p; i++) cout << arr[w][i] << endl;
        cout << "Galho " << c+1 << ":" << endl;
        cout << "Numero total de enfeites: " << arr[w][p] << endl;    
        if (++c) cout << endl;
    }

    return 0;
}