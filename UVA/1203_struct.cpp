#include <bits/stdc++.h>

using namespace std;

struct Argus {
    int ID, period;
};

struct cmp {
    bool operator() (Argus a, Argus b) {
        if(a.period != b.period)
            return a.v > b.v;
        return a.ID > b.ID;
    }
};

int main() {
    priority_queue<Argus, vector<Argus>, cmp> pq;
    char in[21];
    int ID, period, K;
    Argus tmp;
    while(scanf("%s", in), in[0] != '#') {
        scanf("%d %d", &ID, &period);
        tmp.ID = ID, tmp.period = period;
        pq.push(tmp);
    }
    scanf("%d", &K);
    while(K--) {
        tmp = pq.top();
        printf("%d\n", tmp.ID);
        pq.pop();
        tmp.period += tmp.period;
        pq.push(tmp);
    }
    return 0;
}