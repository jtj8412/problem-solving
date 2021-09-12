#include <string>
#include <vector>
#include <queue>
using namespace std;

struct DATA { int sheep = 0, wolf = 0, able = 0, visited = 0; };

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0, n = info.size(), root_child = 0, visited[1 << 18] = {}, able;
    vector<int> edge_vec[18];
    queue<DATA> q;

    for (int i = 0; i < edges.size(); ++i) {
        edge_vec[edges[i][0]].push_back(edges[i][1]);
        if (edges[i][0] == 0) root_child |= (1 << edges[i][1]);
    }

    q.push(DATA{1, 0, root_child, 1});

    while (!q.empty()) {
        DATA data = q.front(); q.pop();
        if (answer < data.sheep) answer = data.sheep;
        for (int i = 0, bit = 1; i < n; ++i, bit <<= 1) {
            if (!(data.able & bit) || (visited[data.visited | bit])) continue;
            if (info[i] == 1 && data.sheep <= data.wolf + 1) continue;
            visited[data.visited | bit] = 1;
            able = 0;
            for (auto j : edge_vec[i]) able |= (1 << j);
            if (info[i] == 0) q.push(DATA({data.sheep + 1, data.wolf, data.able | able ^ bit, data.visited | bit}));
            else q.push(DATA({data.sheep, data.wolf + 1, data.able | able ^ bit, data.visited | bit}));
        }
    }

    return answer;
}