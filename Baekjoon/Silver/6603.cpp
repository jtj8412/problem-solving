//----------------------------------------------------------------------------------
// [ 로또 ] https://www.acmicpc.net/problem/6603
//----------------------------------------------------------------------------------

#include <iostream>

int k, arr[12], visited[12];

void logic(int idx, int cnt) {
    if (cnt == 6) {
        for (int i = 0; i < k; ++i) {
            if (visited[i]) printf("%d ", arr[i]);
        }
        printf("\n");
    } else if (idx < k) {
        visited[idx] = 1;
        logic(idx + 1, cnt + 1);
        visited[idx] = 0;
        logic(idx + 1, cnt);
    }
}

int main() {
    while (true) {
        // init
        scanf("%d", &k);
        if (k == 0) break;
        for (int i = 0; i < k; ++i) scanf("%d", &arr[i]);

        // logic
        logic(0, 0);
        printf("\n");
    }
}