//----------------------------------------------------------------------------------
// [ 7. Reverse Integer ] https://leetcode.com/problems/reverse-integer/
//----------------------------------------------------------------------------------

#include <iostream>

class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while (x > 9 || x < -9) {
            ret *= 10;
            ret += x % 10;
            x /= 10;
        }
        if (abs(ret) > 214748364) return 0;
        ret *= 10;
        if (ret > 2147483638) {
            if (ret % 100 + x > 47) return 0;
        }
        else if (ret < -2147483639) {
            if (ret % 100 + x < -48) return 0;
        }
        ret += x;
        return ret;
    }
};
