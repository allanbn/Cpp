#include <iostream> 

using namespace std;

struct tiro {
    int p;
    int v;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

// input: 1, 3, 500 5, 300 4, 30 2, 10, 680;
int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        int n;
        cin >> n;
        tiro arr[n+1];
        int i;
        for (i = 0; i < n; i++) {
            cin >> arr[i].v >> arr[i].p;
        }
        int k, res;
        cin >> k; 
        cin >> res;
        int mochila[n+1][k+1];
        for (i = 0; i <= n; i++) mochila[i][0] = 0;
        for (i = 0; i <= k; i++) mochila[0][i] = 0;
        int j;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= k; j++) {
                if (j < arr[i-1].p) mochila[i][j] = mochila[i-1][j];
                else mochila[i][j] = max(mochila[i-1][j], (arr[i-1].v + mochila[i-1][j-arr[i-1].p]));
            }
        }
        if (mochila[n][k] >= res) cout << "Missao completada com sucesso\n";
        else cout << "Falha na missao\n";
    }
    return 0;
}