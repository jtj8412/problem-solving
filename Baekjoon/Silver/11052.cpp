//----------------------------------------------------------------------------------
// [ 카드 구매하기 ] https://www.acmicpc.net/problem/11052
//----------------------------------------------------------------------------------

#include <iostream>

int main() {
    int n, arr[1001] = {}, i, j, dp[1001] = {};

    // init
    scanf("%d", &n);

    // logic
    for (i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        for (j = 1; j <= i; ++j) {
            if (dp[i] < dp[i-j] + arr[j]) dp[i] = dp[i-j] + arr[j];
        }
    }

    printf("%d", dp[n]);
}