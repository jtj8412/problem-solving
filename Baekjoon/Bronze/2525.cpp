#include <bits/stdc++.h>

const int DAY_TO_MINUTES = 60 * 24;

int main() {
	int a, b, c, m = 0;
	scanf("%d %d\n%d", &a, &b, &c);
	m = (a * 60 + b + c) % DAY_TO_MINUTES;
	printf("%d %d", m / 60, m % 60);
}