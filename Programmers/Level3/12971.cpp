//----------------------------------------------------------------------------------
// [ 스티커 모으기(2) ] https://programmers.co.kr/learn/courses/30/lessons/12971
//
// 배열 0부터 차레대로 스티커를 붙여 합을 누적시킬 때 현재 스티커를 붙이려는 지점의 
// -2번째 또는 -3번째 지점에 붙여졌을 때의 합을 참고하면 된다는 점에서 착안
//----------------------------------------------------------------------------------

#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> sticker) {
    int dp[2][100000] = {}, size = sticker.size();
    
    if (sticker.size() <= 3) return *max_element(sticker.begin(), sticker.end());
    
    dp[0][0] = sticker[0]; dp[0][2] = sticker[2] + sticker[0]; 
    dp[1][1] = sticker[1]; dp[1][2] = sticker[2];
    for (int i = 3; i < size; ++i) {
        dp[0][i] = max(dp[0][i-2], dp[0][i-3]) + sticker[i];
        dp[1][i] = max(dp[1][i-2], dp[1][i-3]) + sticker[i];
    }

    return max(max(max(dp[0][size-2], dp[0][size-3]), dp[1][size-1]), dp[1][size-2]);
}