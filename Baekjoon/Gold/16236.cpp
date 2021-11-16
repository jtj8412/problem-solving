//----------------------------------------------------------------------------------
// [ 아기 상어 ] https://www.acmicpc.net/problem/16236
//
// 매번 다음 루트를 찾을 때 bfs를 사용하는 방식입니다.
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

struct DATA { int x, y; };

const int dx[] = {0, -1, 1, 0}, dy[] = {-1, 0, 0, 1};
int N, board[20][20], weight = 2;
DATA my_pos;

int next_pos() {
    queue<DATA> q;
    DATA res = {100, 100};
    int visited[20][20] = {}, cnt = 0, size = 1, dist = 1;
    q.push(DATA({my_pos.x, my_pos.y}));
    visited[my_pos.y][my_pos.x] = 1;
    while (!q.empty()) {
        DATA cur = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[ny][nx] || board[ny][nx] > weight) continue;
            if (board[ny][nx] == 0 || board[ny][nx] == weight) {
                q.push(DATA{nx, ny});
                visited[ny][nx] = 1;
            } else if (ny < res.y || (ny == res.y && nx < res.x)){
                res.x = nx; res.y = ny;
            }
        }
        if (++cnt == size) {
            if (res.x != 100) {
                my_pos = res;
                return dist;
            }
            cnt = 0;
            size = q.size();
            dist++;
        }
    }
    return 0;
}

int logic() {
    int time = 0, step = -1, cnt = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
        scanf("%d", &board[i][j]);
        if (board[i][j] == 9) {
            my_pos.x = j; my_pos.y = i;
            board[i][j] = 0;
        }
    }
    while (step) {
        step = next_pos();
        board[my_pos.y][my_pos.x] = 0;
        time += step;
        if (++cnt == weight) {
            cnt = 0;
            weight++;
        }
    }
    return time;
}

int main() {
    printf("%d", logic());
}