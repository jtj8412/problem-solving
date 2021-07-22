/* 올바른 괄호 */

#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    int s_size = s.size(), i;
    stack<int> stk;

    for (i = 0; i < s_size; ++i) {
        if (s[i] == '(') {
            stk.push(0);
        } else {
            if (stk.empty()) return false;
            stk.pop();
        }
    }
    if (!stk.empty()) return false;

    return true;
}