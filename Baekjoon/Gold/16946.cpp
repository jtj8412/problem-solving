//----------------------------------------------------------------------------------
// [ 벽 부수고 이동하기 4 ] https://www.acmicpc.net/problem/16946
// 
// 어떤 벽에 도달할 수 있는 길의 개수를 구하기 위해 역으로 생각하여
// 어떤 경로에서 길의 개수를 구하고 그 개수를 인근 벽에게 더해주는 방식입니다.
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int visited[1000][1000] = {}, N, M;
vector<string> board, answer;

void bfs(int startX, int startY, int token)
{
    queue<pair<int,int>> q, q2;
    int cnt = 1;

    q.push(make_pair(startX, startY));
    visited[startY][startX] = token;

    while (!q.empty()) {
        pair<int, int> pos = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = pos.first + dx[i], ny = pos.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= M || ny >= N || visited[ny][nx] == token) continue;

            if (board[ny][nx] != '0') q2.push(make_pair(nx, ny));
            else { q.push(make_pair(nx, ny)); ++cnt; }
            visited[ny][nx] = token;
        }
    }

    while (!q2.empty()) {
        char& ch = answer[q2.front().second][q2.front().first]; q2.pop();
        int val = ((ch - '0') + cnt) % 10;
        ch = val + '0';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    board.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }
    answer = board;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (visited[i][j] || board[i][j] != '0') continue;
            bfs(j, i, i * 1001 + j + 1);
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << answer[i] << "\n";
    }
}