#include <iostream>

using namespace std;

int main() {
    unsigned int v, m, maior = 0;
    cin >> v >> m;
    if (v > maior) maior = v;
    unsigned int i;
    unsigned int arr[m];
    for (i = 0; i < m; i++) {
        cin >> arr[i];
        if (arr[i] > maior) maior = arr[i];
    }
    unsigned int arr1[maior+1];
    unsigned int j;
    arr1[0] = 1;
    for (i = 0; i < m; i++) {
        for (j = maior; j >= arr[i]; j--) {
            if (arr1[j-arr[i]] == 1) arr1[j] = 1;
        }
    }
    if (arr1[v] == 1) cout << "S\n";
    else cout << "N\n";   
    return 0;
}