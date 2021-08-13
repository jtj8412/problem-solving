//----------------------------------------------------------------------------------
// [ 14. Longest Common Prefix ] https://leetcode.com/problems/longest-common-prefix/
//----------------------------------------------------------------------------------

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = strs[0];

        for (int i = 1, j; i < strs.size(); ++i) {
            for (j = 0; strs[i][j] != '\0' && ret[j] != '\0' && strs[i][j] == ret[j]; ++j);
            ret.erase(j, ret.size() - j);
        }

        return ret;
    }
};