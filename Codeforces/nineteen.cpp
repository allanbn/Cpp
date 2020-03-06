#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    int n = 0, i = 0, e = 0, t = 0, c = 0;
    string in;
    cin >> in;
    string::iterator it1 = in.begin();
    string::iterator it2 = in.end();
    while (it1 != it2) {
        if (*it1 == 'n') n++;
        if (*it1 == 'i') i++;
        if (*it1 == 'e') e++;
        if (*it1 == 't') t++;
        it1++;
    }
    if (n >= 3 && i >= 1 && e >= 3 && t >= 1) {
        n = (n-1) >> 1;
        e /= 3;
        c = min(min(n, i), min(e, t));
    }
    cout << c << endl;
    return 0;
}