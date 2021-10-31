//----------------------------------------------------------------------------------
// [ 벽 부수고 이동하기 ] https://www.acmicpc.net/problem/2206
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

struct DATA {
    int x, y, isCrash = 0, cnt = 1;
};

int main() {
    const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
    vector<string> board;
    queue<DATA> q;
    int n, m, answer = -1;

    scanf("%d %d\n", &n, &m);
    board.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }

    q.push({0, 0, 0, 1});
    while (!q.empty()) {
        DATA& data = q.front(); q.pop();
        if (data.isCrash && board[data.y][data.x] == '3') continue;
        for (int i = 0; i < 4; ++i) {
            int nx = data.x + dx[i], ny = data.y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n || board[ny][nx] == '3' || (data.isCrash && board[ny][nx] >= '1')) continue;
            if (nx == m - 1 && ny == n - 1) { answer = data.cnt + 1; break; }
            q.push({nx, ny, (board[ny][nx] == '1') ? 1 : 0, data.cnt + 1});
            board[ny][nx] = (data.isCrash) ? '2' : '3';
        }
    }

    cout << answer << endl;
}