//----------------------------------------------------------------------------------
// [ 최소직사각형 ] https://programmers.co.kr/learn/courses/30/lessons/86491
//----------------------------------------------------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int n = sizes.size();
    vector<pair<int,int>> dp(n);
    
    dp[0] = make_pair(sizes[0][0], sizes[0][1]);
    for (int i = 1; i < n; ++i) {
        int w1 = max(dp[i-1].first, sizes[i][0]), h1 = max(dp[i-1].second, sizes[i][1]);
        int w2 = max(dp[i-1].first, sizes[i][1]), h2 = max(dp[i-1].second, sizes[i][0]);
        if (w1 * h1 > w2 * h2) {
            dp[i].first = w2; 
            dp[i].second = h2;
        }
        else {
            dp[i].first = w1; 
            dp[i].second = h1;
        }
    }

    return dp[n-1].first * dp[n-1].second;
}