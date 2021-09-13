//----------------------------------------------------------------------------------
// [ 알파벳 찾기 ] https://www.acmicpc.net/problem/10809
//----------------------------------------------------------------------------------

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec(26, -1);
    char s[101];

    scanf("%s", s);

    for (int i = 0; s[i] != '\0'; ++i) {
        if (vec[s[i] - 'a'] == -1) vec[s[i] - 'a'] = i;
    }

    for (auto i : vec) printf("%d ", i);
}