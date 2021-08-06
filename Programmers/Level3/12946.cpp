/* 
[ 하노이의 탑 ]

- 나의 해설
원판 cnt개를 from에서 to로 옮기기
1. from에서 원판 cnt-1개를 임시위치(not from, not to)로 이동 (재귀)
2. from에 남은, 가장 큰 원판 1개를 to로 이동
3. 임시위치로 옮긴 원판 cnt-1개를 to로 이동 (재귀)
*/

#include <vector>
using namespace std;

vector<vector<int>> answer;

void logic(int cnt, int from, int to, int tmp) {
    if (cnt == 1) 
        answer.push_back(vector<int>({from, to}));
    else {
        logic(cnt - 1, from, tmp, to);
        logic(1, from, to, tmp);
        logic(cnt - 1, tmp, to, from);
    }
}

vector<vector<int>> solution(int n) {
    logic(n, 1, 3, 2);
    return answer;
}