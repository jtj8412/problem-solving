#include <bits/stdc++.h>
using namespace std;

vector<string> colors = { 
	"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" 
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s[3];
	cin >> s[0] >> s[1] >> s[2];

	map<string, int> dict;
	for (int i = 0; i < colors.size(); ++i) {
		dict.insert(make_pair(colors[i], i));
	}

	printf("%lld", (dict[s[0]] * 10 + dict[s[1]]) * (long long)pow(10, dict[s[2]]));
}