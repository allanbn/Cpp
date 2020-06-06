#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        int c = 0;
        while (n <= m) {
            string str = to_string(n);
            int flag = 0;
            for (string::iterator it1 = str.begin(); it1 != str.end(); it1++) {
                for (string::iterator it2 = it1+1; it2 != str.end(); it2++) {
                    if (*it1 == *it2) {
                        flag = 1;
                        break;
                    }
                }
            }
            if (!flag) c++;
            n++;
        }
        printf("%d\n", c);
    }
    return 0;
}