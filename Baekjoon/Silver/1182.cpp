//----------------------------------------------------------------------------------
// [ 부분수열의 합 ] https://www.acmicpc.net/problem/1182
//----------------------------------------------------------------------------------

#include <iostream>

int n, s, arr[20], answer = 0;

void logic(int idx = 0, int val = 0, int is_zero = 1) {
    if (idx == n) {
        if (s == val && !is_zero) ++answer;
        return;
    }
    logic(idx + 1, val + arr[idx], 0);
    logic(idx + 1, val, is_zero);
}

int main() {
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    logic();
    printf("%d", answer);
}