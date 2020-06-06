#include <bits/stdc++.h>

using namespace std;

int main() {
    map < string , char > data;
    data["=.==="]        = 'a';
    data["===.=.=.="]    = 'b';
    data["===.=.===.="]    = 'c';
    data["===.=.="]        = 'd';
    data["="]        = 'e';
    data["=.=.===.="]    = 'f';
    data["===.===.="]        = 'g';
    data["=.=.=.="]    = 'h';
    data["=.="]        = 'i';
    data["=.===.===.==="]    = 'j';
    data["===.=.==="]        = 'k';
    data["=.===.=.="]    = 'l';
    data["===.==="]        = 'm';
    data["===.="]        = 'n';
    data["===.===.==="]        = 'o';
    data["=.===.===.="]    = 'p';
    data["===.===.=.==="]    = 'q';
    data["=.===.="]        = 'r';
    data["=.=.="]     = 's';
    data["==="]        = 't';
    data["=.=.==="]        = 'u';
    data["=.=.=.==="]    = 'v';
    data["=.===.==="]        = 'w';
    data["===.=.=.==="]    = 'x';
    data["===.=.===.==="]    = 'y';
    data["===.===.=.="]    = 'z';
    data["===.===.===.===.==="]    = '0';
    data["=.===.===.===.==="]    = '1';
    data["=.=.===.===.==="]    = '2';
    data["=.=.=.===.==="]    = '3';
    data["=.=.=.=.==="]    = '4';
    data["=.=.=.=.="]    = '5';
    data["===.=.=.=.="]    = '6';
    data["===.===.=.=.="]    = '7';
    data["===.===.===.=.="]    = '8';
    data["===.===.===.===.="]    = '9';
    data["=.===.=.===.=.==="]  = '.';
    data["===.===.=.=.===.==="]  = ',';
    data["=.=.===.===.=.="]  = '?';
    data["=.===.===.===.===.="]  = '\'';
    data["===.=.===.=.===.==="]  = '!';
    data["===.=.=.===.="]    = '/';
    data["===.=.===.===.="]    = '(';
    data["===.=.===.===.=.==="]  = ')';
    data["=.===.=.=.="]    = '&';
    data["===.===.===.=.=.="]  = ':';
    data["===.=.===.=.===.="]  = ';';
    data["===.=.=.=.==="]    = '=';
    data["=.===.=.===.="]    = '+';
    data["===.=.=.=.=.==="]  = '-';
    data["=.=.===.===.=.==="]  = '_';
    data["=.===.=.=.===.="]  = '"';
    data["=.===.===.=.===.="]  = '@';
    string line;
    int n,tc = 0;
    cin  >>  n;
    getline(cin,line);
    while(n--) {
        if(tc != 0) cout << endl;
        int dot = 0;
        getline(cin,line);
        string text;
        for(int i = 0;  i < line.size() ; i++ ){
            if(line[i] == '.') dot++;
            else{
                if(dot == 3) text += " ";
                else if(dot == 7)  text += "  ";
                else if(dot == 1) text += '.';
                text +=  line[i];
                dot = 0;
            }
        }
        line  = text;
        stringstream word;
        word << line;

        while(word >> line) {
            cout << data[line];

            if(word.good()){
                char ch = word.get();
                     ch = word.peek();
                 if(ch == ' ' ) cout << " " ;
            }
        }
        cout << endl;
    }
    return 0;
}