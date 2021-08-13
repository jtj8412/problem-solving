//----------------------------------------------------------------------------------
// [ 13. Roman to Integer ] https://leetcode.com/problems/roman-to-integer/
//----------------------------------------------------------------------------------

#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> dict = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}, {' ', 0}
        };
        int ret = 0;

        s += ' ';

        for (int i = 0; i < s.size() - 1; ++i) {
            if (dict[s[i]] < dict[s[i+1]]) ret -= dict[s[i]];
            else ret += dict[s[i]];
        }


        return ret;
    }
};