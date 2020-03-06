#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int registers[11];
    int RAM[1001];
    int num_cmd, p;
    char cmd[5];
    int cases;
    int c = 0;
    cin >> cases;
    fgets(cmd, sizeof(cmd), stdin);
    fgets(cmd, sizeof(cmd), stdin);
    while (cases--) {
        p = 0;
        if (c > 0) printf("\n");
        memset(registers, 0, 11*sizeof(int));
        memset(RAM, 0, 1001*sizeof(int));
        c++;
        // carrega tudo pra ram;
        while(fgets(cmd, sizeof(cmd), stdin) != NULL) {
            if (cmd[0]=='\n') break;
            RAM[p] = (cmd[0] - '0') * 100 + (cmd[1] - '0') * 10 + (cmd[2] - '0');
            p++;
        }
        num_cmd = 0;
        p = 0;
        bool stop = false;
        while(!stop) {
            int a1, a2, cmdint;
            cmdint = RAM[p] / 100;
            a1 = (RAM[p] % 100) / 10;
            a2 = RAM[p] % 10;
            switch (cmdint) {
                case 1:
                    stop = true;
                    break;
                case 2 :
                    registers[a1] = a2;
                    p++;
                    break;
                case 3 :
                    registers[a1] = (registers[a1] + a2) % 1000;
                    p++;
                    break;
                case 4 :
                    registers[a1] = (registers[a1] * a2) % 1000;
                    p++;
                    break;
                case 5 :
                    registers[a1] = registers[a2];
                    p++;
                    break;
                case 6 :
                    registers[a1] = (registers[a1] + registers[a2]) % 1000;
                    p++;
                    break;
                case 7 :
                    registers[a1] = (registers[a1] * registers[a2]) % 1000;
                    p++;
                    break;
                case 8 :
                    registers[a1] = RAM[registers[a2]];
                    p++;
                    break;
                case 9 :
                    RAM[registers[a2]] = registers[a1];
                    p++;
                    break;
                case 0 :
                    if (registers[a2] != 0) {
                        p = registers[a1];
                    } else {
                        p++;
                    }
                    break;
                default:
                    break;
            }
            num_cmd++;
        }
        printf("%d\n", num_cmd);
    }
    return 0;
}