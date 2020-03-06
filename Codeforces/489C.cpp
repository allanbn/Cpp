#include <bits/stdc++.h>

/**
 * Lenght = 2, Sum = 15
 * Answer = 69, 96
 *   
 * 
*/

using namespace std;

int main() {
    int m, s;
    scanf("%d %d", &m, &s);
    if ((m > 1 && s < 1) || s > 9*m) printf("-1 -1\n");
    else {
        int _min = s, _max = s ,idx = m-1, j;
        while (idx >= 0) {
            j = max(0, _min-9*idx);
            if (idx == m-1 && _min && j == 0) j = 1;
            printf("%d", j);
            idx--;
            _min -= j;
        }
        printf(" ");
        idx = m;
        while (idx != 0) {
            j = min(9, _max);
            printf("%d", j);
            idx--;
            _max -= j;
        }
        printf("\n");
    }
    return 0;
}