#include <iostream>

using namespace std;

typedef struct strPath {
    int v;
    int p; // 0 = diagonal, 1 = acima, 2 = esquerda; 
}str;
 

int len(char *a) {
    int i;
    for (i = 0; a[i] != '\0'; i++) {
        ;
    }
    return i;
}

int main() {
    char A[8], B[8];
    while(cin >> A && cin >> B) {
        int lenA = len(A);
        int lenB = len(B);
        str m[lenA+1][lenB+1];
        int i;
        for (i = 0; i <= lenA; i++) {
            m[i][0].v = 0;
            m[i][0].p = -1;
        }
        for (i = 0; i <= lenB; i++) {
            m[0][i].v = 0;
            m[0][i].p = -1;
        }
        int j;
        for (i = 1; i <= lenA; i++) {
            for (j = 1; j <= lenB; j++) {
                if (A[i-1] == B[j-1]) {
                    m[i][j].v = 1 + m[i-1][j-1].v;
                    m[i][j].p = 0;
                }
                else if (m[i-1][j].v >= m[i][j-1].v) {
                    m[i][j].v = m[i-1][j].v;
                    m[i][j].p = 1;
                }
                else {
                    m[i][j].v = m[i][j-1].v;
                    m[i][j].p = 2;
                }
            }
        }
        cout << m[lenA][lenB].v << "\n";
    }
    return 0;
}