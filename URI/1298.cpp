#include <bits/stdc++.h>

using namespace std;

//int g[605][605];
int visited[605*605];
char in[605];

vector<int> g[605*605];

void BFS(int i) {
    visited[i] = 1;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
        i = q.front();
        q.pop();
        for (int k : g[i]) {
            if (!visited[k]) {
                q.push(k);
                visited[k] = 1;
            }
        }
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int i, j;
        int x = (2*n+1)*2*n;
        int a, b, c, d;
        for (i = 0; i < x; i++) {
            g[i].clear();
            visited[i] = 0;
        }
        for (i = 0; i < n*2-1; i++) {
            scanf("%s", in);
            if (i % 2) {
                g[i*(2*n+1)].push_back((i+1)*(2*n+1));
                g[(i+1)*(2*n+1)].push_back(i*(2*n+1));
            }
            else {
                g[i*(2*n+1)+2*n].push_back((i+1)*(2*n+1)+2*n);
                g[(i+1)*(2*n+1)+2*n].push_back(i*(2*n+1)+2*n);
            }
            for (j = 0; j < n; j++) {
                if (i % 2) {
                    a = i*(2*n+1)+2*j+1; 
                    b = i*(2*n+1)+2*j+2;
                    c = (i+1)*(2*n+1)+2*j+1; 
                    d = (i+1)*(2*n+1)+2*j+2;
                }
                else {
                    a = i*(2*n+1)+2*j;
                    b = i*(2*n+1)+2*j+1;
                    c = (i+1)*(2*n+1)+2*j;
                    d = (i+1)*(2*n+1)+2*j+1;
                    if (i == 0) {
                        g[b].push_back(b+1);
                        g[b+1].push_back(b);
                    }
                    if (i == 2*n-2) {
                        g[d].push_back(d+1);
                        g[d+1].push_back(d);
                    }
                }
                if (in[j] == 'H') {
                    g[a].push_back(b);
                    g[b].push_back(a);
                    g[c].push_back(d);
                    g[d].push_back(c);
                }
                else {
                    g[a].push_back(c);
                    g[c].push_back(a);
                    g[b].push_back(d);
                    g[d].push_back(b);
                }
            }
        }
        int r = -1;
        for (i = 0; i < x; i++) {
            if (!visited[i]) {
                r++;
                BFS(i);
            }
        }
        printf("%d\n", r);
    }
    return 0;
}