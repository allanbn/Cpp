#include <iostream>

using namespace std;

int len(char *a) {
    int i;
    for (i = 0; a[i] != '\0'; i++) {
        ;
    }
    return i;
}

int main() {
    char A[52], B[52];
    while(cin.getline(A, sizeof(A)) && cin.getline(B, sizeof(B))) {
        int lenA = len(A);
        int lenB = len(B);
        int i, j;
        int cont, maior = 0;
        for (i = 0; i < lenA; i++) {
            for (j = 0; j < lenB; j++) {
                cont = 0;
                if (A[i] == B[j]) {
                    for (int a = i, b = j; a < lenA, b < lenB; a++, b++) {
                        if (A[a] != B[b]) break;
                        cont++;
                    }
                    if (cont > maior) maior = cont;
                }
            }
        }
        cout << maior << "\n";
    }
    return 0;
}