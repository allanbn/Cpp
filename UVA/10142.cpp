#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    string endline = "";
    while (cases--) {
        int n;
        cin >> n;
        vector<string> names(n);
        vector<bool> outB(n, false);
        cin.ignore();
        for (int i = 0; i < n; ++i)
            getline(cin, names[i]);
        string temp;
        getline(cin, temp);
        vector<vector<int> > votos;
        while (temp != "") {
            stringstream ss;
            ss << temp;
            vector<int> order(n);
            for (int i = 0; i < n; ++i) {
                ss >> order[i];
                --order[i];
            }
            votos.push_back(order);
            if (cin.eof())
                break;
            getline(cin, temp);
        }
        int vts = votos.size();
        vector<int> posVotos(vts, 0);
        int winner = -1;
        vector<int> counting(n, 0);
        for (int i = 0; i < vts; ++i)
            ++counting[votos[i][0]];
        while (winner == -1) {
            for (int i = 0; i < vts; i++) {
                bool out = false;
                while (outB[votos[i][posVotos[i]]]) {
                    posVotos[i]++;
                    out = true;
                }
                if (out) counting[votos[i][posVotos[i]]]++;
            }
            int h = 0, l = 1000;
            for (int i = 0; i < n; ++i) {
                if (outB[i]) continue;
                if (counting[i] > h) h = counting[i];
                if (counting[i] < l) l = counting[i];
            }
            if (h == l || h * 2 > vts)
                winner = h;
            else {
                for (int i = 0; i < n; ++i)
                    if (counting[i] == l)
                        outB[i] = true;
            }
        }
        cout << endline;
        endline = "\n";
        for (int i = 0; i < n; ++i)
            if (counting[i] == winner && !outB[i])
                cout << names[i] << '\n';
    }
}
