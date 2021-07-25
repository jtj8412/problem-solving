/* 이진 변환 반복하기 */

#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer = {1, 0};
    int size = 0, prev, i = 0, bit;

    if (s == "1") return vector<int>({0, 0});

    for (i = 0; i < s.size(); ++i) {
        if (s[i] == '1') ++size;
        else ++answer[1];
    }

    while (size != 1) {
        prev = size; size = 0;
        for (bit = 1; bit <= prev; bit <<= 1) {
            if (bit & prev) ++size;
            else ++answer[1];
        }
        ++answer[0];
    }
    
    return answer;
}