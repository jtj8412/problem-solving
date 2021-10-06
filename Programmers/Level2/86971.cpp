//----------------------------------------------------------------------------------
// [ 전력망을 둘로 나누기 ] https://programmers.co.kr/learn/courses/30/lessons/86971
//----------------------------------------------------------------------------------

#include <string>
#include <vector>
using namespace std;

int answer = 0x7fffffff, N;
vector<vector<int>> edges;
vector<bool> visited;

int logic(int v) {
    int sum = 1;
    visited[v] = true;
    for (int i = 0; i < edges[v].size(); ++i) {
        if (visited[edges[v][i]]) continue;
        sum += logic(edges[v][i]);
    }
    answer = min(abs(sum + sum - N), answer);
    return sum;
}

int solution(int n, vector<vector<int>> wires) {
    N = n;
    edges.resize(N);
    visited.resize(N);
    for (int i = 0; i < wires.size(); ++i) {
        edges[wires[i][0] - 1].push_back(wires[i][1] - 1);
        edges[wires[i][1] - 1].push_back(wires[i][0] - 1);
    }
    logic(0);
    return answer;
}