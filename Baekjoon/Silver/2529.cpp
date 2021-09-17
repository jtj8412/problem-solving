//----------------------------------------------------------------------------------
// [ 부등호 ] https://www.acmicpc.net/problem/2529
//----------------------------------------------------------------------------------

#include <iostream>

char ans[11], s[11];
int n;

void logic(int i, int idx, int cur, int stk, char ch, int d) {
    if (i == n) {
        if (stk) { 
            for (int j = stk; j >= 0; --j) ans[idx++] = (cur - j * d) + '0'; 
        }
        else ans[idx] = cur + '0';
        ans[n+1] = '\0';
        return;
    }

    if (s[i] == ch) {
        if (stk) {
            for (int j = stk; j >= 0; --j) ans[idx++] = (cur - j * d) + '0';
            cur += (stk + 1) * -d;
            stk = 0;
        } else {
            ans[idx++] = cur + '0';
            cur += -d;
        }
    } else {
        ++stk;
    }

    logic(i + 1, idx, cur, stk, ch, d);
}

int main() {
    // init
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%s", s + i);

    // logic
    logic(0, 0, 9, 0, '>', 1);
    printf("%s\n", ans);
    logic(0, 0, 0, 0, '<', -1);
    printf("%s\n", ans);
}

