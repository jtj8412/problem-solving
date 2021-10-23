//----------------------------------------------------------------------------------
// [ 퇴사 ] https://www.acmicpc.net/problem/14501
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int N, T[15], P[15], ans = 0;

void bf(int idx, int val) {
    if (idx == N) {
        ans = max(ans, val);
    } else {
        bf(idx + 1, val);
        if (idx + T[idx] <= N) bf(idx + T[idx], val + P[idx]);
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d %d", &T[i], &P[i]);
    bf(0, 0);   
    printf("%d\n", ans);
}