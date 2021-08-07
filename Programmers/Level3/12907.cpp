/*
[ 거스름돈 ]

- 해설
어떤 금액에서 1, 1~2 ... 1~i 번째 동전으로 만들 수 있는 경우의 수를 누적
*/

#include <vector>
using namespace std;
int solution(int n, vector<int> money) {
    vector<int> dp(n + 1);

    for (int i = 0; i <= n; i += money[0]) dp[i] = 1;
    for (int i = 1; i < money.size(); ++i) {
        for (int j = money[i]; j <= n; ++j) dp[j] += dp[j - money[i]];
    }

    return dp[n];
}