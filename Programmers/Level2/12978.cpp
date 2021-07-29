/* 배달 */

#include <vector>
using namespace std;

int route[51][51] = {}, cache[51], N, K;
vector<int> route_vec[51];

void logic(int idx = 1, int sum = 0, long long visited = 1 << 1) {
    for (auto i : route_vec[idx]) {
        if (visited & ((long long)1 << i) || sum + route[idx][i] > K || sum + route[idx][i] >= cache[i]) continue;
        cache[i] = sum + route[idx][i];
        logic(i, cache[i], visited | ((long long)1 << i));
    }
}

int solution(int n, vector<vector<int>> road, int k) {
    int answer = 1, i;
    N = n; K = k;

    fill_n(cache, N + 1, 500001);
    fill_n((int*)route, 51 * 51, 10001);
    for (i = 0; i < road.size(); ++i) {
        route[road[i][0]][road[i][1]] = route[road[i][1]][road[i][0]] = min(route[road[i][0]][road[i][1]], road[i][2]);
        route_vec[road[i][0]].push_back(road[i][1]);
        route_vec[road[i][1]].push_back(road[i][0]);
    }
    logic();

    for (i = 1; i <= N; ++i) {
        if (cache[i] <= K) ++answer;
    }
    return answer;
}