//----------------------------------------------------------------------------------
// [ 벽 부수고 이동하기 ] https://www.acmicpc.net/problem/2206
//
// 0: 길
// 1: 벽
// 2: 길을 isCrash=1 이 방문
// 3: 벽을 부수고 방문
// 4: 길을 isCrash=0 이 방문
//
// 3, 4의 경우 재방문할 수 없습니다.
// 2의 경우 isCrash=0 인 경우에만 방문 할 수 있습니다.
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

struct DATA {
    int x, y, isCrash = 0, cnt = 1;
};

int main() {
    const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
    char board[1000][1000]; 
    queue<DATA> q;
    int n, m, answer = -1;

    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%s", board[i]);

    q.push({0, 0, 0, 1});
    board[0][0] = '4';
    while (!q.empty()) {
        DATA& data = q.front(); q.pop();
        if (data.x == m - 1 && data.y == n - 1) {answer = data.cnt; break; }
        if (data.isCrash && board[data.y][data.x] == '4') continue;

        for (int i = 0; i < 4; ++i) {
            int nx = data.x + dx[i], ny = data.y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n || (data.isCrash && board[ny][nx] != '0') || board[ny][nx] >= '3') continue;

            if (board[ny][nx] == '0') board[ny][nx] = (data.isCrash) ? '2' : '4';
            else if (board[ny][nx] == '1') board[ny][nx] = '3';
            else board[ny][nx] = '4'; // if (board[ny][nx] == '2')
            q.push({nx, ny, (board[ny][nx] == '3' || data.isCrash) ? 1 : 0, data.cnt + 1});
        }
    }

    printf("%d\n", answer);
}