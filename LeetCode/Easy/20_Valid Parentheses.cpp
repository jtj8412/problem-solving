//----------------------------------------------------------------------------------
// [ 20. Valid Parentheses ] https://leetcode.com/problems/valid-parentheses/
//
// 닫는괄호 앞의 두 비트는 11(3) 이고, 열린괄호는 그렇지 않다
// 괄호 (), [], {} 의 6~7번째 비트는 순서대로 01(1), 10(2), 11(3) 이다
// '0b' 로 표현하는 숫자는 '0x' 로 표현하는 숫자에 비해 많이 느리다
//----------------------------------------------------------------------------------

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        for (int i = 0, size = s.size(); i < size; ++i)  {
            if ((s[i] & 3) == 1) {
                if (stk.empty() || stk.top() != (s[i] & 0x60)) return false;
                stk.pop();
            } else {
                stk.push(s[i] & 0x60);
            }
        }
        return (stk.empty()) ? true : false;
    }
};