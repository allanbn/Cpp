#include <iostream> 
#include <cstring>
using namespace std;
int fib_bottomup(int n, unsigned int* arr) {
    if (n <= 1) return 1;
    return arr[n-1] + arr[n-2];
} 

int main() {
    unsigned int arr[10001], in;
    cin >> in;
    memset(arr, 0, 10001*sizeof(int));
    int i;
    for (i = 0; i <= in; i++) {
        if (arr[i] == 0) {
            arr[i] = fib_bottomup(i, arr);    
        }
    }
    cout << arr[in] << endl;
    return 0;
}