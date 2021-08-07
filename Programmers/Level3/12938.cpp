/* 
[ 최고의 집합 ]

- 나의 해설
최고의 집합은 x, x ... x+1, x+1 이 되는 경우
(s/n)*cnt + (s/n + 1)*(n - cnt) = s, 라는 공식이 만들어짐 (s/n = x값, cnt = x의 개수)
cnt = (val + 1) * n - s, 위 식을 cnt를 구하기 위한 공식으로 정제
x를 cnt개만큼, x+1를 (n-cnt)만큼 answer에 삽입
*/

#include <vector>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int val = s / n, cnt = (val + 1) * n - s, i;
    if (val == 0) return vector<int>({-1});
    for (i = 0; i < cnt; ++i) answer.push_back(val);
    for (i = 0; i < n - cnt; ++i) answer.push_back(val + 1);
    return answer;
}