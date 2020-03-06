#include <bits/stdc++.h>
char matrix[101][101];

using namespace std;

int main() {

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int cases = 0;
    int n, m;
    while (cin >> n >> m, n > 0 && m > 0) {
        cases++;
        if (cases > 1) cout << "\n";
        memset(matrix, '.', 101*101*sizeof(char));
        int i, j;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> matrix[i][j];                   
            }
        }
        cout << "Field #" << cases << ":\n";
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (matrix[i][j] == '*') cout << "*";
                else {
                    int count = 0;
                    int x, y;
                    for (x = i-1; x <= i+1; x++) 
                        for (y = j-1; y <= j+1; y++)
                            if (matrix[x][y] == '*') count++;
                    cout << count;
                }
            }
            cout  << "\n";
        }
    }
    return 0;
}