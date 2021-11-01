//----------------------------------------------------------------------------------
// [ 벽 부수고 이동하기 3 ] https://www.acmicpc.net/problem/16933
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

struct DATA {
    int x, y, crash = 0, cnt = 1;
};

const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int visited[1000][1000] = {}, N, M, K, answer = -1;
vector<string> board;

void logic() {
    queue<DATA> q;

    q.push({0, 0, 0, 1});
    visited[0][0] = 1;
    while (!q.empty()) {
        DATA data = q.front(); q.pop();
        int isMorning = !(data.cnt & 1);
        if (data.x == M - 1 && data.y == N - 1) {answer = data.cnt; break; }
        if (visited[data.y][data.x] < data.crash + 1) continue;

        for (int i = 0; i < 4; ++i) {
            int nx = data.x + dx[i], ny = data.y + dy[i];
            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            int ncrash = (board[ny][nx] == '1') ? data.crash + 1 : data.crash;
            if (((data.crash == K || isMorning) && board[ny][nx] == '1') || (visited[ny][nx] && visited[ny][nx] <= ncrash + 1)) continue;
            q.push({nx, ny, ncrash, data.cnt + 1});
            visited[ny][nx] = ncrash + 1;
        }

        if (isMorning) {
            data.cnt++;
            q.push(data);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K;
    board.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }
    logic();
    printf("%d\n", answer);
}