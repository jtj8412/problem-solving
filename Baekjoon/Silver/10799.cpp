//----------------------------------------------------------------------------------
// [ 쇠막대기 ] https://www.acmicpc.net/problem/10799
//----------------------------------------------------------------------------------

#include <iostream>

int main() {
    int ans = 0, stk = 0, i;
    char cmd[100001];

    scanf("%s", cmd);

    for (i = 0; cmd[i] != 0; ++i) {
        if (cmd[i] == '(') {
            if (cmd[i+1] == ')') ans += stk;    // laser
            else ++ans; ++stk;                  // stick start
        }
        else --stk;                             // stick end
    }

    printf("%d\n", ans);
}
