/* 최댓값과 최솟값 */

#include <string>
#include <vector>

#define LONG_LONG_MAX 9223372036854775807ll
#define LONG_LONG_MIN (-LONG_LONG_MAX-1)

using namespace std;

string solution(string s) {
    int s_size = s.size();
    long long min = LONG_LONG_MAX, 
        max = LONG_LONG_MIN;
    string tmp = "",
        min_s = "",
        max_s = "";

    for (int i = 0; i <= s_size; ++i) {
        if (s[i] == ' ' || s[i] == '\0') {
            long long val = stoll(tmp);
            
            if (val < min) {
                min = val;
                min_s = tmp;
            }
            if (val > max) {
                max = val;
                max_s = tmp;
            }
            tmp.clear();
        } else {
            tmp += s[i];
        }
    }
    
    return min_s + " " + max_s;
}