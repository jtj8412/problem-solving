#include <bits/stdc++.h>
using namespace std;

#define FIRST(ch) ((ch - '0') * 1000 + 10000)
#define SECOND(ch) ((ch - '0') * 100 + 1000)
#define THIRD(ch) ((ch - '0') * 100)

int main() {
	int ans = 0;
	char str[6] = {};
	scanf("%[^\n]s", str);

	if (str[0] == str[2] && str[0] == str[4])
		ans = FIRST(str[0]);
	else if (str[0] == str[2] || str[0] == str[4])
		ans = SECOND(str[0]);
	else if (str[2] == str[4])
		ans = SECOND(str[2]);
	else if (str[0] >= str[2] && str[0] >= str[4])
		ans = THIRD(str[0]);
	else if (str[2] >= str[0] && str[2] >= str[4])
		ans = THIRD(str[2]);
	else
		ans = THIRD(str[4]);

	printf("%d", ans);
}