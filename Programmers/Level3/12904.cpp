/* 가장 긴 팰린드롬 */

#include <string>
using namespace std;

bool compare(char *a, char *b, int size) {
    for (int i = 0, j = 0; i < size; ++i, --j) {
        if (*(a + i) != *(b + j)) return false;
    }
    return true;
}

int solution(string s) {
    int answer = 0;
    for (int i = s.size(), half = (i >> 1); i >= 1; --i, half = (i >> 1)) {
        for (int j = 0; j <= s.size() - i; ++j) {
            if (compare(&s[j], &s[j + i - 1], half)) {
                answer = i;
                break;
            }
        }
        if (answer) break;
    }
    return answer;
}