/* 가장 먼 노드 */

#include <vector>
#include <queue>
using namespace std;

vector<int> edge[20001];
int cache[20001] = {};

int solution(int n, vector<vector<int>> edge_vvec) {
    int answer = 0, vertex, i, max = 0;
    queue<int> q;

    for (auto edge_info : edge_vvec) {
        edge[edge_info[0]].push_back(edge_info[1]);
        edge[edge_info[1]].push_back(edge_info[0]);
    }

    q.push(1);
    cache[1] = 1;
    while (!q.empty()) {
        vertex = q.front(); q.pop();
        for (auto vtx : edge[vertex]) {
            if (cache[vtx]) continue;
            cache[vtx] = cache[vertex] + 1;
            q.push(vtx);
        }
    }

    for (i = 1; i <= n; ++i) { if (cache[i] > max) max = cache[i]; }
    for (i = 1; i <= n; ++i) { if (cache[i] == max) ++answer; }

    return answer;
}