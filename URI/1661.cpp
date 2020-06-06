#include <iostream>
#include <cmath>

using namespace std;

typedef long long int lli;

int main() {
    lli n, sum;
    while (cin >> n, n) {
        sum = 0;
        lli* arr = (lli*)malloc((n+1)*sizeof(lli));
        int i;
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (i = 1; i < n; i++) {
            sum += abs(arr[i-1]);
            arr[i] += arr[i-1];
        }
        cout << sum << "\n";
        free(arr);
    }
    return 0;
}