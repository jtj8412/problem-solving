//----------------------------------------------------------------------------------
// [ 1920. Build Array from Permutation ] https://leetcode.com/problems/build-array-from-permutation/
//----------------------------------------------------------------------------------

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int size = nums.size(), i = 0;
        vector<int> ans(size);
        
        while (i < size) {
            ans[i++] = nums[nums[i]];
        }
        
        return ans;
    }
};