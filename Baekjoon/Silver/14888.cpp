//----------------------------------------------------------------------------------
// [ 연산자 끼워넣기 ] https://www.acmicpc.net/problem/14888
//----------------------------------------------------------------------------------

#include <iostream>

int min = 0x7fffffff, max = -0x7fffffff, n, arr[11], cnt[4];

void logic(int val, int idx) {
    if (idx == n) {
        if (val > max) max = val;
        if (val < min) min = val;
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (cnt[i] == 0) continue;
        --cnt[i];
        if (i == 0) logic(val + arr[idx], idx + 1);
        else if (i == 1) logic(val - arr[idx], idx + 1);
        else if (i == 2) logic(val * arr[idx], idx + 1);
        else logic(val / arr[idx], idx + 1);
        ++cnt[i];
    }
}

int main() {
    // init
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    for (int i = 0; i < 4; ++i) scanf("%d", &cnt[i]);

    // logic
    logic(arr[0], 1);

    printf("%d\n%d", max, min);
}