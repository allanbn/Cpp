#include <bits/stdc++.h>

using namespace std;

int main() {
    char in[10];
    while (cin >> in, !cin.eof()) {
        int a = (int) in[0]-'0';
        int b = (int) (in[2]-'0')*10;
        // cout << b << endl;
        int c = (int) in[3]-'0';
        // cout << c << endl;
        int d = b+c;
        if (a == 8) d += 60;
        else {
            d+=60;
            if (d > 60) a++, d-=60;
            if (a > 8){
                d += 60*(a-8);
            }
            else if (a < 8) d = 0;
        }        
        cout << "Atraso maximo: " << d << endl;
        // else cout << "Atraso maximo: 0\n";     
    }   
    return 0;
}