/* 짝지어 제거하기 */

#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    stack<char> stk;
    int s_size = s.size();
    
    if (s_size % 2 != 0) return 0;

    for (int i = 0; i < s_size; ++i) {
        if (stk.size() != 0 && s[i] == stk.top()) stk.pop();
        else stk.push(s[i]);
    }

    if (stk.size() != 0) return 0;

    return 1;
}