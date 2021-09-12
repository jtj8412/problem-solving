//----------------------------------------------------------------------------------
// [ 후위 표기식2 ] https://www.acmicpc.net/problem/1935
//----------------------------------------------------------------------------------

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<double> stk;
    int n, arr[26], i;
    char s[101];

    // input
    scanf("%d", &n);
    scanf("%s", s);
    for (i = 0; i < n; ++i) scanf("%d", arr + i);

    // logic
    for (i = 0; s[i] != '\0'; ++i) {
        if (isalpha(s[i])) {    // number
            stk.push(arr[s[i] - 'A']);
        } else {                // operator
            double val = stk.top(); stk.pop();
            if (s[i] == '+') stk.top() += val;
            else if (s[i] == '-') stk.top() -= val;
            else if (s[i] == '*') stk.top() *= val;
            else stk.top() /= val;
        }
    }

    printf("%.2f", stk.top());
}

