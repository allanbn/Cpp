#include <iostream>
#include <cstring>

#define VMAX 100000

using namespace std;

void print_subset(int r[], int n) {
    cout << "{";
    for(int i = 0; i < n; i++) {
        cout << r[i] << " ";
    }
    cout << "}" << endl;
}

void backtracking(int a[], int r[], int k, int n) {
    if(k == n) {
        print_subset(r,n);
    }
    else{
        bool pres[VMAX];
        memset(pres,0,VMAX*sizeof(bool));
        for(int i = 0; i < k; i++) pres[r[i]] = true;
        k++;
        for(int i = 0; i < n; i++) {
            if(!pres[a[i]]) {
                r[k-1] = a[i];
                backtracking(a,r,k,n);
            }
        }
    }
}

void generate_permutations(int a[], int n) {
    int r[n];
    backtracking(a,r,0,n);
}

int main() {
    int a[] = {1,3,4,5};
    generate_permutations(a,4);
    return 0;
}
