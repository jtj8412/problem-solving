//----------------------------------------------------------------------------------
// [ 후위 표기식 ] https://www.acmicpc.net/problem/1918
//----------------------------------------------------------------------------------

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string answer;
    stack<int> stk;
    char s[101];
    int priority[8] = {0, 0, 2, 1, 0, 1, 0, 2}; // operator - 40

    // input
    scanf("%s", s);

    // logic
    for (int i = 0; s[i] != '\0'; ++i) {
        if (isalpha(s[i])) {    // alpha
            answer += s[i];
        } else {                // operator
            while (s[i] != '(' && !stk.empty() && priority[stk.top() - 40] >= priority[s[i] - 40]) {
                answer += stk.top(); stk.pop();
                if (priority[answer.back() - 40] == priority[s[i] - 40]) break;
            }
            
            if (s[i] == ')') answer.pop_back();
            else stk.push(s[i]);
        }
    }
    while (!stk.empty()) {
        answer += stk.top(); stk.pop();
    }

    cout << answer;
}

