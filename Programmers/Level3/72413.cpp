//----------------------------------------------------------------------------------
// [ 합승 택시 요금 ] https://programmers.co.kr/learn/courses/30/lessons/72413
//
// 최단거리를 찾는 방법은 bfs + priority_queue를 이용한 로직을 사용
// 1. 출발지점부터 임의의 정점까지 보다 최단거리로 가는 루트를 찾고 해당 루트까지 합승
// 2. 1에서 합승한 정점부터 각자의 도착지점까지 최단거리 루트를 찾아 이동
// 3. 1,2 결과 나오는 택시요금이 기존 answer보다 적게 나올 경우 answer 갱신
// 4. 1,2,3 반복 결과 answer의 최솟값이 정답
//----------------------------------------------------------------------------------

#include <vector>
#include <queue>
using namespace std;

const int inf = 0x7fffffff;
int fare_arr[201][201] = {};
vector<int> fare_vec[201];

int search(int start, int end, int n) {
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, inf);
    pair<int,int> from;
    int i, to;

    if (start == end) return 0;

    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        from = pq.top(); pq.pop();
        if (from.second == end) return dist[end];
        if (from.first > dist[from.second]) continue;
        for (i = 0; i < fare_vec[from.second].size(); ++i) {
            to = fare_vec[from.second][i];
            if (from.first + fare_arr[from.second][to] >= dist[to]) continue;
            dist[to] = from.first + fare_arr[from.second][to];
            pq.push(make_pair(dist[to], to));
        }
    }
    return inf;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = inf, ret_a, ret_b, to;
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, inf);
    pair<int,int> from;

    for (int i = 0, size = fares.size(); i < size; ++i) {
        fare_vec[fares[i][0]].push_back(fares[i][1]);
        fare_vec[fares[i][1]].push_back(fares[i][0]);
        fare_arr[fares[i][0]][fares[i][1]] = fare_arr[fares[i][1]][fares[i][0]]= fares[i][2];
    }
    
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        from = pq.top(); pq.pop();
        if (from.first > dist[from.second]) continue;
        ret_a = search(from.second, a, n); ret_b = search(from.second, b, n);
        if (ret_a != inf && ret_b != inf) answer = min(answer, ret_a + ret_b + from.first);
        for (int i = 0; i < fare_vec[from.second].size(); ++i) {
            to = fare_vec[from.second][i];
            if (from.first + fare_arr[from.second][to] >= dist[to]) continue;
            dist[to] = from.first + fare_arr[from.second][to];
            pq.push(make_pair(dist[to], to));
        }
    }

    return answer;
}