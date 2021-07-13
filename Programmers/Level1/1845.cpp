/* 폰켓몬 */

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
