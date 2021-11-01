//----------------------------------------------------------------------------------
// [ 벽 부수고 이동하기 2 ] https://www.acmicpc.net/problem/14442
// 
// 방문을 기록하는 visited 배열에 crash + 1 의 값을 넣습니다.
// 만약 재방문시 visited에 자신의 crash + 1 보다 같거나 작은 값을 같고 있으면
// 재방문할 필요가 없다고 여기고 패스합니다.
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

struct DATA {
    int x, y, crash = 0, cnt = 1;
};

int visited[1000][1000] = {};
char board[1000][1000] = {};

int main() {
    const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
    queue<DATA> q;
    int n, m, k, answer = -1;

    scanf("%d %d %d\n", &n, &m, &k);
    for (int i = 0; i < n; ++i) scanf("%s", board[i]);

    q.push({0, 0, 0, 1});
    visited[0][0] = 1;
    while (!q.empty()) {
        DATA& data = q.front(); q.pop();
        if (data.x == m - 1 && data.y == n - 1) {answer = data.cnt; break; }
        if (visited[data.y][data.x] < data.crash + 1) continue;

        for (int i = 0; i < 4; ++i) {
            int nx = data.x + dx[i], ny = data.y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            int ncrash = (board[ny][nx] == '1') ? data.crash + 1 : data.crash;
            if ((data.crash == k && board[ny][nx] == '1') || (visited[ny][nx] && visited[ny][nx] <= ncrash + 1)) continue;
            q.push({nx, ny, ncrash, data.cnt + 1});
            visited[ny][nx] = ncrash + 1;
        }
    }

    printf("%d\n", answer);
}