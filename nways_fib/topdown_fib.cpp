#include <iostream>
#include <cstring>
using namespace std;
int fib_mem(int n, unsigned int* arr) {
    if (n == 0) return 0;
    else if (n <= 2) return 1;
    else {
        if (arr[n] == 0) arr[n] = fib_mem(n-1, arr) + fib_mem(n-2, arr);
    }
    return arr[n];        
}

int main() {
    unsigned int arr[10001];
    int in;
    memset(arr, 0, 10001*sizeof(int));
    cin >> in;
    cout << fib_mem(in, arr) << endl; 
    return 0;
}