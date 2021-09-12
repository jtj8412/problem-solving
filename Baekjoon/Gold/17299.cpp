//----------------------------------------------------------------------------------
// [ 오등큰수 ] https://www.acmicpc.net/problem/17299
//----------------------------------------------------------------------------------

#include <iostream>
#include <stack>
using namespace std;

int ans[1000000], cnt[1000001] = {}, arr[1000000] = {};

int main() {
    int val, n, i;
    stack<pair<int,int>> stk;

    setvbuf(stdout, NULL, _IOFBF, 0x7fffffff);
    stk.push(make_pair(-1, 0x7fffffff));

    scanf("%d", &n);

    for (i = 0; i < n; ++i) {
        scanf("%d", &val);
        ++cnt[val];
        arr[i] = val;
    }

    for (i = 0; i < n; ++i) {
        val = arr[i];
        while (stk.top().second < cnt[val]) {
            ans[stk.top().first] = val;
            stk.pop();
        }
        stk.push(make_pair(i, cnt[val]));
    }

    while (!stk.empty()) {
        ans[stk.top().first] = -1;
        stk.pop();
    }

    for (i = 0; i < n; ++i) {
        fprintf(stdout, "%d ", ans[i]);
    }

    fflush(stdout);
}