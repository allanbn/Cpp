#include <bits/stdc++.h>

using namespace std;

int GCDsimp (int num, int den) {
	// cout << num << den;
	if (den > 0) return GCDsimp(den, num % den);
	return num;
}

int main() {
	int num, den, apostas[101], cont = -1;
	while (scanf("%d %d", &num, &den) != EOF) {
		apostas[++cont] = GCDsimp(num, den);
		if (apostas[cont] > 5) cout << "Noel" << '\n';
		else cout << "Gnomos" << '\n';
	}
	for (int i = cont; i >= 0; i--) {
		cout << apostas[i] << " ";
	}
	cout << '\n';
	return 0;
}