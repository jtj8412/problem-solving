/* 숫자 문자열과 영단어 */

#include <string>

using namespace std;

const string N[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solution(string s) {
    int answer = 0,
        s_size = s.size(), i, j;

    for (i = 0; i < s_size; ++i) {
        answer *= 10;
        if (s[i] >= '0' && s[i] <= '9') {
            answer += s[i] - '0';
        } else {
            for (j = 0; j < 10; ++j) {
                if (s[i] == N[j][0] && s[i + 1] == N[j][1]) {
                    answer += j;
                    i += N[j].length() - 1; 
                    break;
                }
            }
        }
    }

    return answer;
}