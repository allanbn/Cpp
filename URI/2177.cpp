#include <bits/stdc++.h>

#define lli long long int

using namespace std;


lli dstp(lli i, lli j, lli k, lli l) {
	lli d = sqrt(pow((i-j), 2) + pow((k-l), 2));
    return d;
}

int main() {
    vector<lli> out;
    // vector<int> res;
    lli x, y, n;
    scanf("%lld %lld %lld", &x, &y, &n);
    // games arr[n+1];
    int i;
    lli xi, yi, ti;
    lli tmp = 0;
    
    for (i = 0; i < n; i++) {
        scanf("%lld %lld %lld", &xi, &yi, &ti);
        // ti--;
        lli dist = dstp(x, xi, y, yi);
        // cout << dist << endl;
        if (dist < ti) {
            // tmp += dist+ti;
            out.push_back(i+1);
        }
    }
    if (out.size()) {
        for (i = 0; i < out.size(); i++) {
            printf("%lld", out[i]);
            if (i < out.size() - 1) printf(" ");
        }
        printf("\n");
    }
    else printf("-1\n");
    
    return 0;
}