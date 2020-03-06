#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int l, r, k;
    cin >> l >> r >> k;
    vector<long long int> ans;
    long long int _r = log2(r), res = 1;
    long long int i;
    for (i = 0; i <= _r; i++) {   
        if (l <= res && res <= r) ans.push_back(res);
        // if (res > r/k) break;
        res *= k;
    }
    int size = (int)ans.size();
    if (size) {
        for (i = 0; i < size; i++) {
            cout << ans[i];
            if (i < size-1) cout << " ";
        }
        cout << "\n";
    }
    else cout << "-1\n";
    return 0;
}