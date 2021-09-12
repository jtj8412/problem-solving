//----------------------------------------------------------------------------------
// [ 오큰수 ] https://www.acmicpc.net/problem/17298
//----------------------------------------------------------------------------------

#include <iostream>
#include <stack>
using namespace std;

int ans[1000000];

int main() {
    int val, n, i;
    stack<pair<int,int>> stk;

    setvbuf(stdout, NULL, _IOFBF, 0x7fffffff);
    stk.push(make_pair(-1, 0x7fffffff));

    scanf("%d", &n);

    for (i = 0; i < n; ++i) {
        scanf("%d", &val);
        while (stk.top().second < val) {
            ans[stk.top().first] = val;
            stk.pop();
        }
        stk.push(make_pair(i, val));
    }

    while (!stk.empty()) {
        ans[stk.top().first] = -1;
        stk.pop();
    }

    for (i = 0; i < n; ++i) {
        printf("%d ", ans[i]);
    }

    fflush(stdout);
}