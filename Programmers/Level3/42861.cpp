/* 섬 연결하기 */

/*  
크러스컬 알고리즘 (Kruskal's Algorithm)

최소비용신장트리 알고리즘
1. 가중치(거리) 낮은 순으로 간선 추가
2. 사이클이 발생할 경우 스킵
시간복잡도: O(ElogV)
*/

#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent(100);

int get_parent(int vertex) {
    if (parent[vertex] == vertex) return vertex;
    return (parent[vertex] = get_parent(parent[vertex]));
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0, i, a, b;
    for (i = 0; i < n; ++i) parent[i] = i;
    sort(costs.begin(), costs.end(), [](const vector<int> &a, const vector<int> &b)->bool{return a[2]<b[2];});
    for (i = 0; i < n - 1; ++i) {
        a = get_parent(costs[i][0]);
        b = get_parent(costs[i][1]);
        if (a == b) { n++; continue; }
        if (a < b) parent[b] = a;
        else parent[a] = b;
        answer += costs[i][2];
    }
    return answer;
}