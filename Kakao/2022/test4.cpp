#include <vector>
#include <queue>
using namespace std;

struct DATA { int arrow, visited = 0, score = 0, apeach; };

vector<int> solution(int n, vector<int> info) {
    vector<int> answer(11, 0);
    queue<DATA> q;
    int max_diff = 0, max_visited = 0, max_apeach = 0;

    for (int i = 0; i < info.size(); ++i) {
        if (info[i]) max_apeach += (10 - i);
    }
    
    q.push(DATA({n, 0, 0, max_apeach}));
    for (int i = 0; i < 10; ++i) {
        int len = q.size();
        for (int j = 0; j < len; ++j) {
            DATA data = q.front(); q.pop();

            q.push(data);
            if (data.arrow > 0 && info[i] < data.arrow) {
                DATA newData = DATA({data.arrow - info[i] - 1, data.visited | (1 << i), data.score + (10 - i), data.apeach - ((info[i] == 0) ? 0 : (10 - i))});
                if (max_diff <= newData.score - newData.apeach) {
                    max_diff = newData.score - newData.apeach;
                    max_visited = newData.visited;
                }
                q.push(newData);
            }
        }
    }

    if (max_diff == 0) return vector<int>({-1});
    int arrow = 0;
    for (int i = 0, bit = 1; i <= 10; ++i, bit <<= 1) {
        if (max_visited & bit) {
            answer[i] = info[i] + 1;
            arrow += answer[i];
        }
    }
    if (arrow != n) answer[10] = arrow;

    return answer;
}