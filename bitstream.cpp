#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string bitstream = "111000101000100100010001";
    unsigned char buffer[100];
    memset(buffer,0, 100);
    int ind = 0;
    int cont_bits = 0;

    for(int i = 0; i < bitstream.size(); i++) {
        buffer[ind] = (buffer[ind] << 1) | ((int)(bitstream[i]-'0')); //desloca um bit para a esquerda para adicionar o próximo bit
        cont_bits++;
        if(cont_bits == 8) { //verifica se finalizou um byte
            cont_bits = 0;
            ind++;
        }
    }
    
    cout << bitstream << endl;
    //mostrando os bits a partir do buffer
    for(int i = 0; i < ind; i++) {
        for(int k = 7; k >= 0; k--) {
            cout << (int)((buffer[i] >> k) & 1);
        }
    }
    return 0;
}