#include <bits/stdc++.h>
using namespace std;

int logic() {
	int a, b, n, tbl[10] = { 0, };

	scanf("%d %d", &a, &b);

	n = a % 10;
	tbl[n] = 1;

	for (int i = 2; i <= b; ++i) {
		n = (n * a) % 10;

		if (tbl[n]) {
			int order = ((b - 1) % (i - 1)) + 1;
			n = find(tbl, tbl + 10, order) - tbl;
			break;
		}

		tbl[n] = i;
	}

	return (n == 0) ? 10 : n;
}

int main() {
	int tc;
	scanf("%d", &tc);
	
	for (int t = 0; t < tc; ++t) {
		printf("%d\n", logic());
	}
}