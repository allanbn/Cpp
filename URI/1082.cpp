#include <bits/stdc++.h>

using namespace std;

int visited[27];
int g[27][27];
vector<char> vec;

void DFS(int i,  int v) {
	vec.push_back(i+'a');
	visited[i] = 1;
	int j;
	for (j = 0; j < v; j++) {
		if ((g[i][j]) && (!visited[j])) DFS(j, v);
	}
}

int main() {

	int n;
	int outc = 0;
	scanf("%d", &n);
	while (n--) {
		int c = 0;
		memset(visited, 0, sizeof(visited));
		memset(g, 0, sizeof(g));
		int v, e;
		scanf("%d %d", &v, &e);
		int i;
		char x, y;
		for (i = 0; i < e; i++) {
			cin >> x >> y;
			g[x-'a'][y-'a'] = 1;
			g[y-'a'][x-'a'] = 1;
		}
		if (outc) printf("\n");
		printf("Case #%d:\n", ++outc);
		for (i = 0; i < v; i++) {
			if (!visited[i]) {
				DFS(i , v);
				int j;
				sort(vec.begin(), vec.end());
				if (vec.size() > 0) c++;
				for (j = 0; j < vec.size(); j++) {
					printf("%c,", vec[j]);
				}
				vec.clear();
				printf("\n");
			}
		}
		printf("%d connected components\n", c);
	}
	printf("\n");
	return 0;
}