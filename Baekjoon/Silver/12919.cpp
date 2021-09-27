//----------------------------------------------------------------------------------
// [ A와 B 2 ] https://www.acmicpc.net/problem/12919
//----------------------------------------------------------------------------------

#include <iostream>
#include <string.h>
using namespace std;

int main() {
    char s1[2][51], s2[51];
    int s1_size, s2_size, i, j, l, r, dir = 0, answer = 0, reverse = 0;

    scanf("%s", s1[0]); scanf("%s", s2);
    s1_size = strlen(s1[0]), s2_size = strlen(s2);
    for (i = 0; i < s1_size; ++i) s1[1][i] = s1[0][s1_size - i - 1];

    for (int k = 0; k < 2; ++k) {
        for (i = 0; i <= s2_size - s1_size; ++i) {
            for (j = 0; j < s1_size; ++j) {
                if (s1[k][j] != s2[i + j]) break;
            }
            if (j != s1_size) continue;

            l = i;
            r = l + s1_size - 1;
            dir = k;
            reverse = 0;

            while (!(l == 0 && r == s2_size - 1)) {
                if (!dir) j = ++r;
                else j = --l;

                if (j < 0 || j >= s2_size) break;

                if (s2[j] == 'B') {
                    dir = !dir;
                    ++reverse;
                }
            }

            if (l == 0 && r == s2_size - 1 && ((k == 0 && reverse % 2 == 0) || (k == 1 && reverse % 2 == 1))) {
                answer = 1;
                break;
            }
        }
        if (answer == 1) break;
    }

    printf("%d", answer);
}
