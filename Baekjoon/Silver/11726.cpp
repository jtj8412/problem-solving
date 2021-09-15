//----------------------------------------------------------------------------------
// [ 2xn 타일링 ] https://www.acmicpc.net/problem/11726
//----------------------------------------------------------------------------------

#include <iostream>

int main() {
    int dp[1001] = {0, 1, 2}, n, i;

    // init
    scanf("%d", &n);

    // logic
    for (i = 3; i <= n; ++i) dp[i] = (dp[i-1] + dp[i-2]) % 10007;

    printf("%d", dp[n]);
}