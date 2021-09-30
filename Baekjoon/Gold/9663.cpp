//----------------------------------------------------------------------------------
// [ N-QUEEN ] https://www.acmicpc.net/problem/9663
//----------------------------------------------------------------------------------

#include <iostream>

int N, answer = 0;

void dfs(int cnt, int left, int mid, int right) {
    if (cnt == N) { ++answer; return; }

    for (int i = 0, bit = 1; i < N; ++i, bit <<= 1) {
        if ((bit & left) || (bit & mid) || (bit & right)) continue;
        dfs(cnt + 1, (left | bit) >> 1, mid | bit, (right | bit) << 1);
    }
}

int main() {
    scanf("%d", &N);
    dfs(0, 0, 0, 0);
    printf("%d", answer);
}