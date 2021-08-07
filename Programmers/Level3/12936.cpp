/* 
[ 줄 서는 방법 ]

- 나의 해설
i번째 자리의 숫자가 다음으로 바뀌려면 (n - i - 1)! 개의 경우가 필요하다
*/

#include <vector>
using namespace std;

long long factorial(int n) {
    long long ret = 1;
    for (int i = 1; i <= n; ++i) ret *= i;
    return ret;
}

vector<int> solution(int n, long long k) {
    vector<int> answer, number(n);
    long long fact;
    --k;
    for (int i = 0; i < n; ++i) number[i] = i + 1;
    for (int i = n - 1, cnt; i > 0; --i) {
        cnt = 0;
        fact = factorial(i);
        while ((k - fact) >= 0) {
            k -= fact;
            ++cnt;
        }
        answer.push_back(number[cnt]);
        number.erase(number.begin() + cnt);
    }
    answer.push_back(number[0]);
    return answer;
}