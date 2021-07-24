/* 괄호 회전하기 */

#include <string>
#include <stack>
#include <queue>

using namespace std;

#define ABS(n) (n < 0 ? -n : n)

bool is_open(char ch) { return (ch == '(' || ch == '{' || ch == '[') ? true : false; }
bool is_correct(char open, char close) { return ABS(open - close) < 3 ? true : false; }

int solution(string s) {
    int answer = 1,
        len = s.size(),
        s_size = len * 2, end = len,
        i, check = 0;
    stack<char> stk;
    queue<int> q;
    
    if (len % 2 != 0) return 0;

    s += s;

    for (i = 0; i < end; ++i) {
        if (is_open(s[i])) {
            stk.push(s[i]);
        } else if (stk.empty() || !is_correct(stk.top(), s[i])) {
            check = i + 1;
            end = (i + 1) + len;
            if (end > s_size - 1) return 0;
            while (!stk.empty()) stk.pop();
            while (!q.empty()) q.pop();
        } else {
            stk.pop();
            if (!stk.empty()) continue;
            q.push(i - check + 1);
            check = i + 1;
        }
    }

    while ((end += q.front()) < s_size) { ++answer; q.pop();}

    return answer;
}