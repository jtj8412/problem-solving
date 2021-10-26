//----------------------------------------------------------------------------------
// [ 가르침 ] https://www.acmicpc.net/problem/1062
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int N, K, flags[50] = {}, answer = 0;

void logic(int idx, int visited, int cnt) {
    if (idx == 26) {
        int sum = 0;

        for (int i = 0; i < N; ++i) {
            if ((visited & flags[i]) == flags[i]) ++sum;
        }
        
        answer = max(answer, sum);
        return;
    }

    logic(idx + 1, visited, cnt);
    if (!(visited & (1 << idx)) && cnt < K) {
        logic(idx + 1, visited | (1 << idx), cnt + 1);
    }
}

int main() {
    char s[16];

    scanf("%d %d\n", &N, &K);
    for (int i = 0; i < N; ++i) {
        scanf("%s", s);

        for (int j = 4; s[j] != '\0'; ++j) {
            flags[i] |= (1 << (s[j] - 'a'));
        }
    }

    logic(0, 1 << ('a' - 'a') | 1 << ('c' - 'a') | 1 << ('i' - 'a') | 1 << ('n' - 'a') | 1 << ('t' - 'a'), 5);

    printf("%d\n", answer);
}

