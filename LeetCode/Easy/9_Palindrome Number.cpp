//----------------------------------------------------------------------------------
// [ 9. Palindrome Number ] https://leetcode.com/problems/palindrome-number/
//----------------------------------------------------------------------------------

#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> vec;

        if (x < 0) return false;

        while (x != 0) {
            vec.push_back(x % 10);
            x /= 10;
        }

        for (int i = 0; i < vec.size() - i - 1; ++i) {
            if (vec[i] != vec[vec.size() - i - 1]) return false;
        }

        return true;
    }
};
