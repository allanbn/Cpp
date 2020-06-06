#include <bits/stdc++.h>

int invert(int x) {
    int rev = 0;
    while(x) {
        rev *= 10;
        rev += x%10;
        x /= 10;
    }
    return rev;
}

int main() {
    int t, a, b;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &a, &b);
        // BFS
        std::map<int, int> d;
        d.insert(std::pair<int, int>(a, 0));
        std::queue<int> discovered;
        discovered.push(a);
        while(!discovered.empty()) {
            int v = discovered.front();
            discovered.pop();
            if (v == b) {
                break;
            }
            std::vector<int> vec;
            vec.push_back(v+1);
            vec.push_back(invert(v));
            int i;
            for(i = 0; i < vec.size(); i++) {
                if (!d.count(vec[i])) {
                    d.insert(std::pair<int, int>(vec[i], d[v]+1));
                    discovered.push(vec[i]);
                }
            }
        }
        // BFS END
        printf("%d\n", d[b]);
    }
    return 0;
}