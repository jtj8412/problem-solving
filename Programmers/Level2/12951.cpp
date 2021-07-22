/* JadenCase 문자열 만들기 */

#include <string>

int isalpha(char ch) {
    if (ch >= 'A' && ch <= 'Z') return 1;
    if (ch >= 'a' && ch <= 'z') return 2;
    return 0;
}

std::string solution(std::string s) {
    int s_size = s.size(), i, is_alpha;
    char prev = ' ';

    for (i = 0; i < s_size; ++i) {
        is_alpha = isalpha(s[i]);
        if (prev == ' ') {
            if (is_alpha == 2) s[i] -= 32;
        }
        else if (is_alpha == 1) s[i] += 32;
        prev = s[i];
    }
    return s;
}