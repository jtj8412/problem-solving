//----------------------------------------------------------------------------------
// [ 스타트와 링크 ] https://www.acmicpc.net/problem/14889
//----------------------------------------------------------------------------------

#include <iostream>

int arr[20][20], n, answer = 0x7fffffff;

int sum(int visited) {
    int ret = 0;
    for (int i = 0, bit = 1; i < n; ++i, bit <<= 1) {
        if (!(visited & bit)) continue;
        for (int j = i + 1, bit2 = (1 << j); j < n; ++j, bit2 <<= 1) {
            if (!(visited & bit2)) continue;
            ret += arr[i][j] + arr[j][i];
        }
    }
    return ret;
}

void logic(int idx, int visited, int cnt) {
    if (idx == n) {
        if (cnt != (n >> 1)) return;
        int a = sum(visited), b = sum(~visited);
        answer = std::min(std::abs(a - b), answer);
    } else {
        logic(idx + 1, visited, cnt);
        logic(idx + 1, visited | (1 << idx), cnt + 1);
    }
}

int main() {
    // init
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    // logic
    logic(0, 0, 0);

    printf("%d\n", answer);
}