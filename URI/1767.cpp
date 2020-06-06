#include <iostream> 
using namespace std;

struct pacote {
    int qt;
    int p;
};

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        int n;
        cin >> n;
        pacote arr[n+1];
        int i;
        for (i = 0; i < n; i++) {
            cin >> arr[i].qt >> arr[i].p;
        }
        pacote mochila[n+1][51];
        for (i = 0; i <= n; i++) {
            mochila[i][0].qt = 0;
            mochila[i][0].p = 0;
        }
        for (i = 0; i <= 50; i++) {
            mochila[0][i].qt = 0;
            mochila[0][i].p = 0;
        }
        int j;
        pacote a, b;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= 50; j++) {
                a = mochila[i-1][j];
                if (arr[i-1].p > j) b = mochila[0][j];
                else {
                    b = mochila[i-1][j-arr[i-1].p];
                    b.qt += arr[i-1].qt;
                }
                if (a.qt >= b.qt) mochila[i][j] = a;
                else {
                    b.p++;
                    mochila[i][j] = b;
                }
            }
        }
        int melhor = -1, pos = 0;
        for (i = 0; i <= 50; i++){
            if (mochila[n][i].qt > melhor) {
                melhor = mochila[n][i].qt;
                pos = i;
            }
        }
        cout << mochila[n][50].qt << " brinquedos\n";
        cout << "Peso: " << pos << " kg\n";
        cout << "sobra(m) " << (n - mochila[n][50].p) << " pacote(s)\n\n";
    }
    return 0;
}