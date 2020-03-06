#include <bits/stdc++.h>

#define max(x, y) ((x) > (y) ? (x) : (y))
#define swap(x, y) {int tmp; tmp = x, x = y, y = tmp;}
#define N 1000000 // numero maximo possível
#define no 1048576

int A[N+1], tree[no<<1];

void hash_build(int l, int r, int k) {
    if (l == r) tree[k] = A[l];
    if (l < r) {
        int m = (l+r) >> 1;
        hash_build(l, m, k<<1);
        hash_build(m+1, r, (k<<1)+1);
        tree[k] = max(tree[k<<1], tree[(k<<1)+1]);
    }
}

int get_sol(int l, int r, int k, int i, int j) {
    if(l == i && r == j)
        return tree[k];
    if(l < r) {
        int m = (l+r) >> 1;
        if (m >= j)
            return get_sol(l, m, k<<1, i, j);
        else if (m < i)
            return get_sol(m+1, r, (k<<1)+1, i, j);
        else
            return max(get_sol(l, m, k<<1, i, m), get_sol(m+1, r, (k<<1)+1, m+1, j));
    }
}
void sol() {
    long long n;
    int i, len;
    memset(A, 0, sizeof(A));
    memset(tree, 0, sizeof(tree));
    A[1] = 1;
    for(i = 2; i <= N; i++) {
        n = i, len = 1;
        while(n != 1) {
            if(n&1) {
                n = n*3 + 1;
            } else {
                n >>= 1;
            }
            if(n < N && A[n] != 0) {
                len += A[n];
                break;
            }
            len++;
        }
        A[i] = len;
    }
    hash_build(1, N, 1);
}
int main() {
    sol();
    int i, j;
    while(scanf("%d %d", &i, &j) == 2) {
        printf("%d %d ", i, j);
        if(i > j) swap(i, j);
        printf("%d\n", get_sol(1, N, 1, i, j));
    }
    return 0;
}