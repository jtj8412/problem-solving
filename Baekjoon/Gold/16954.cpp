//----------------------------------------------------------------------------------
// [ 움직이는 미로 탈출 ] https://www.acmicpc.net/problem/16954
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

struct DATA { int x, y; };

int logic() {
    const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
    const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
    int visited[8][8] = {}, size = 1, cnt = 0, turn = 1;
    string board[8];
    queue<DATA> q;
    for (int i = 0; i < 8; ++i) cin >> board[i];
    q.push(DATA({0,7}));
    visited[0][0] = 1;
    while (!q.empty()) {
        DATA cur = q.front(); q.pop();
        if (board[cur.y][cur.x] == '.')
        {
            for (int i = 0; i < 9; ++i) {
                int nx = cur.x + dx[i], ny = cur.y + dy[i];
                if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8 || board[ny][nx] == '#' || visited[ny][nx] == turn) continue;
                if (nx == 7 && ny == 0) return 1;
                visited[ny][nx] = turn;
                q.push(DATA({nx, ny}));
            }
        }
        if (++cnt == size) {
            size = q.size();
            cnt = 0;
            turn = min(turn + 1, 9);
            for (int i = 7; i > 0; --i) for (int j = 0; j < 8; ++j) board[i][j] = board[i-1][j];
            for (int i = 0; i < 8; ++i) board[0][i] = '.';
        }
    }
    return 0;
}

int main() {
    printf("%d", logic());
}