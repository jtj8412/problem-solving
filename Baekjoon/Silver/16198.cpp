//----------------------------------------------------------------------------------
// [ 에너지 모으기 ] https://www.acmicpc.net/problem/16198
//----------------------------------------------------------------------------------

#include <iostream>

int N, arr[10], answer = 0;

void dfs(int len, int visited, int sum) {
    if (len == 2) {
        answer = std::max(answer, sum);
        return;
    }

    for (int i = 1, bit = 2, bit2, bit3, j, k; i < N - 1; ++i, bit <<= 1) {
        if (bit & visited) continue;
        for (j = i - 1, bit2 = bit >> 1; bit2 & visited; bit2 >>= 1, --j);
        for (k = i + 1, bit3 = bit << 1; bit3 & visited; bit3 <<= 1, ++k);
        dfs(len - 1, visited | bit, sum + arr[j] * arr[k]);
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", arr + i);
    dfs(N, 0, 0);
    printf("%d", answer);
}