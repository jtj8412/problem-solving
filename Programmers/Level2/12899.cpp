/* 124 나라의 숫자 */

#include <string>

using namespace std;

string solution(int n) {
    string answer = "";
    int sum = 0, add, div, i, j;

    for (i = 0, add = 3; sum < n; ++i, add *= 3) {
        sum += add;
    }

    for (div = add / 9; div != 0; div /= 3) {
        int val = (n / div);
        if (val > 3) val = 3;
        n -= div * val;
        answer += (val == 3) ? '4' : '0' + val;
    }

    for (i = 1; i < answer.size(); ++i) {
        if (answer[i] != '0') continue;
        for (j = i; answer[j] < '2'; --j) answer[j] = '4';
        answer[j] = (answer[j] == '4') ? '2' : '1';
    }   
    
    return answer;
}