#include <iostream>
#include <cstring>

using namespace std;

void print_subset(int a[], bool pres[], int n) {
    cout << "{";
    for(int i = 0; i < n; i++) {
        if(pres[i]) {
            cout << a[i] << " ";
        }
    }
    cout << "}" << endl;
}

void backtracking(int a[], bool pres[], int k, int n) {
    if(k == n) {
        print_subset(a,pres,n);
    }
    else{
        k++;
        pres[k-1] = true;
        backtracking(a,pres,k,n);
        pres[k-1] = false;
        backtracking(a,pres,k,n);
    }
}


int main() {
    int a[] = {1,3,4};
    bool pres[6];
    memset(pres,0,6*sizeof(bool));
    backtracking(a,pres,0,3);
    return 0;
}
