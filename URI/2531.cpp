#include <bits/stdc++.h>

#define N 100001

using namespace std;

int seg_tree[4*N][2];

void make(int p, int l, int r, int *arr) {
    if (l == r) {
        seg_tree[p][0] = arr[l];
        seg_tree[p][1] = arr[l];
    }
    else {
        make(2*p, l, (l+r)/2, arr);
        make(2*p+1, (l+r)/2+1, r, arr);
        seg_tree[p][0] = min(seg_tree[2*p][0], seg_tree[2*p+1][0]);
        seg_tree[p][1] = max(seg_tree[2*p][1], seg_tree[2*p+1][1]);
    }
}

void updt(int p, int l, int r, int x, int v) {
    if (l == r && l == x) {
        seg_tree[p][0] = v;
        seg_tree[p][1] = v;
        return;
    }
    if (x < l || x > r) return;
    updt(2*p, l, (l+r)/2, x, v);
    updt(2*p+1, (l+r)/2+1, r, x, v);
    seg_tree[p][0] = min(seg_tree[2*p][0], seg_tree[2*p+1][0]);
    seg_tree[p][1] = max(seg_tree[2*p][1], seg_tree[2*p+1][1]);
}

pair<int, int> qry(int p, int l, int r, int i, int j) {
    if (l > j || r < i) return {INT_MAX, INT_MIN};
    if (i <= l && r <= j) return {seg_tree[p][0], seg_tree[p][1]};
    pair<int, int> px = qry(2*p, l, (l+r)/2, i , j);
    pair<int, int> py = qry(2*p+1, (l+r)/2+1, r, i, j);
    return {min(px.first, py.first), max(px.second, py.second)};
}

int main() {
    
    int n;
    while (scanf("%d", &n) != EOF && n) {
        int p[n+1];
        int i;
        for (i = 0; i < n; i++) scanf("%d", &p[i]);
          // p, l, r, arr
        make(1, 0, n-1, p);
        int q, a, b, c;
        scanf("%d", &q);
        while (q--) {
            scanf("%d %d %d", &a, &b, &c);
            if (a == 1) {
                updt(1, 0, n-1, b-1, c);
            }
            else {
                pair<int, int> ans = qry(1, 0, n-1, b-1, c-1);
                printf("%d\n", ans.second - ans.first);
            }
        }
    }
    return 0;
}