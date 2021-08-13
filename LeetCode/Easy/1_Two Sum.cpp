//----------------------------------------------------------------------------------
// [ 1. Two Sum ] https://leetcode.com/problems/two-sum/
//
// 1. 맵에 key로 숫자, value로 숫자의 인덱스를 삽입
// 2. n+n = target 경우 검사
// 3. 맵의 임의의 노드를 선택
// 4. (target - 위에서 선택한 노드의 key)를 key로하는 노드가 맵에 있을 경
//    두 노드가 가지고있는 인덱스 값이 정답
//----------------------------------------------------------------------------------

#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        int half = target / 2, half_idx = -1, i, size;

        for (i = 0, size = nums.size(); i < size; ++i) {
            if (nums[i] == half) half_idx = i;
            m.insert(make_pair(nums[i], i));
        }
        
        if (!(target & 1) && m.find(half) != m.end()) {
            if (m[half] != half_idx)
                return vector<int>({m[half], half_idx});
            m.erase(half);
        }

        while (m.find(target - m.begin()->first) == m.end()) {
            m.erase(m.begin());
        }

        return vector<int>({m.begin()->second, m[target - m.begin()->first]});
    }
};
