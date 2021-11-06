//----------------------------------------------------------------------------------
// [ 카드 ] https://www.acmicpc.net/problem/11652
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long val, answer = 0;
    unordered_map<long long, int> dict;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &val);
        if (++dict[val] >= dict[answer]) {
            if (dict[val] != dict[answer] || val < answer) answer = val;
        }
    }
    printf("%d\n", answer);
}