//----------------------------------------------------------------------------------
// [ 1로 만들기 ] https://www.acmicpc.net/problem/1463
//----------------------------------------------------------------------------------

#include <iostream>
#include <queue>

int dp[1000001] = { }; // cnt

int main() {
    int n, val;
    std::queue<int> q; // val

    // init
    scanf("%d", &n);
    q.push(1);

    // logic
    while (true) {
        val = q.front(); q.pop();

        if (val == n) break;
        
        if (val + 1 <= n && !dp[val + 1]) {
            dp[val + 1] = dp[val] + 1;
            q.push(val + 1);
        }
        if (val * 2 <= n && !dp[val * 2]) {
            dp[val * 2] = dp[val] + 1;
            q.push(val * 2);
        }
        if (val * 3 <= n && !dp[val * 3]) {
            dp[val * 3] = dp[val] + 1;
            q.push(val * 3);
        }
    }
    
    printf("%d", dp[val]);
}