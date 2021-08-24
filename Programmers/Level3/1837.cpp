//----------------------------------------------------------------------------------
// [ GPS ] https://programmers.co.kr/learn/courses/30/lessons/1837
//
// i+1 번째 시간에 임의의 정점 k에 위치할 때의 모든 경우 중 오류 수정 비용이 최소인 값을 저장
//----------------------------------------------------------------------------------

#include <vector>
#include <queue>
using namespace std;

const int INF = 0x7fffffff;

int solution(int n, int edge_size, vector<vector<int>> edge_list, int gps_size, vector<int> gps_log) {
    int dp1[201] = {}, dp2[201] = {}, from, to, good, i, j, k, q_size, 
        *prev = dp1, *next = dp2;
    vector<int> edge_vec[201];
    queue<int> q;

    fill(next, next + n + 1, INF);

    for (i = 0; i < edge_size; ++i) {
        edge_vec[edge_list[i][0]].push_back(edge_list[i][1]);
        edge_vec[edge_list[i][1]].push_back(edge_list[i][0]);
    }
    
    q.push(gps_log[0]);
    for (i = 1; i < gps_size; ++i) {
        good = gps_log[i];
        q_size = q.size();
        for (j = 0; j < q_size; ++j) {
            from = q.front(); q.pop();
            for (k = 0; k < edge_vec[from].size(); ++k) {
                to = edge_vec[from][k];
                if (next[to] == INF) q.push(to);
                next[to] = min(next[to], prev[from] + ((to == good) ? 0 : 1));
            }
        }
        swap(prev, next);
        fill(next, next + n + 1, INF);
    }

    return (prev[gps_log.back()] == INF) ? - 1 : prev[gps_log.back()];
}