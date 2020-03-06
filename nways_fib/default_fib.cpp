#include <iostream>
using namespace std;
int fib(int n) {
	if (n <= 1) return 1;
	return fib(n-1) + fib(n-2);
}

int main() {
	int in;
    cin >> in;
	cout << fib(in) << endl;
	return 0;
}