/* 문자열 압축 */

#include <string>

using namespace std;

int solution(string s) {
    int answer = s.length(), len = s.length(), half_len = s.length() / 2;

    for (int i = 1; i <= half_len; ++i) {
        int cnt_sum = 0, idx, cnt = 1;
        string compare = s.substr(0, i);

        for (idx = i; idx < len; idx += i) {
            string cur = s.substr(idx, i);

            if (cur == compare) {
                cnt++;
            } else {
                cnt_sum += (cnt > 1) ? i + to_string(cnt).length() : i;
                compare = cur;
                cnt = 1;
            }
        }

        if (idx == len) cnt_sum += (cnt > 1) ? i + to_string(cnt).length() : i;
        else cnt_sum += compare.length();
        
        answer = min(answer, cnt_sum);

    }
    return answer;
}
