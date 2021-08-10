//----------------------------------------------------------------------------------
// [ 폰켓몬 ] https://programmers.co.kr/learn/courses/30/lessons/1845
//
// 1. 최대한 많은 종류의 폰켓몬을 고르는 경우는 각각 다른 종류를 한 개씩 고르는 경우이다
// 2. 1에서 구한 값을 최댓값인 N / 2 로 제한한다
//----------------------------------------------------------------------------------

#include <vector>
#define MAX_NUM 200000
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0, cnt = 0, cache[MAX_NUM] = {}, select = nums.size() / 2;

    for (int i = 0; i < nums.size(); ++i) {
        int num = nums[i];
        
        if (cache[num] != 0) continue;

        cache[num] = 1;
        cnt++;
    }

    answer = (select > cnt) ? cnt : select;
    return answer;
}
