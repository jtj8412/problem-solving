/* 네트워크 */

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0, i, j, visited[200] = {};
    queue<int> q;

    for (i = 0; i < computers.size(); ++i) {
        if (visited[i]) continue;
        visited[i] = 1;
        ++answer;
        q.push(i);
        while (!q.empty()) {
            for (j = 0; j < n; ++j) {
                if (!computers[q.front()][j] || visited[j]) continue;
                visited[j] = 1;
                q.push(j);
            }
            q.pop();
        }
    }

    return answer;
}