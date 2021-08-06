/* 하노이의 탑 */

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