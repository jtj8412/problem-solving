//----------------------------------------------------------------------------------
// [ 두 동전 ] https://www.acmicpc.net/problem/16197
//----------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct DATA { int x1, y1, x2, y2, val; };

const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
int N, M;
vector<string> board;

int logic(int x1, int y1, int x2, int y2) {
    queue<DATA> q;
    int visited[20][20][20][20] = {};

    q.push(DATA({x1, y1, x2, y2, 0}));
    visited[y1][x1][y2][x2] = 1;
    while (!q.empty()) {
        DATA pos = q.front(); q.pop();
        if (pos.val == 10) return -1;

        for (int i = 0; i < 4; ++i) {
            int cnt = 0;
            DATA next = DATA({(pos.x1 + dx[i]), (pos.y1 + dy[i]), (pos.x2 + dx[i]), (pos.y2 + dy[i]), pos.val + 1});
            if (next.x1 < 0 || next.x1 >= M || next.y1 < 0 || next.y1 >= N) ++cnt;
            if (next.x2 < 0 || next.x2 >= M || next.y2 < 0 || next.y2 >= N) ++cnt;
            if (cnt == 1) return next.val;
            if (cnt == 2) continue;
            if (board[next.y1][next.x1] == '#') { next.x1 = pos.x1; next.y1 = pos.y1; }
            if (board[next.y2][next.x2] == '#') { next.x2 = pos.x2; next.y2 = pos.y2; }
            if (visited[next.y1][next.x1][next.y2][next.x2]) continue;
            visited[next.y1][next.x1][next.y2][next.x2] = 1;
            q.push(next);
        }
    }
    return -1;
}

int main() {
    int pos[2][2] = {{-1}}, answer;

    scanf("%d %d", &N, &M);
    board.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> board[i];    
    }
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
        if (board[i][j] == 'o') {
            if (pos[0][0] == -1) {
                pos[0][0] = j;
                pos[0][1] = i;
            } else {
                pos[1][0] = j;
                pos[1][1] = i;
            }
        }
    }

    answer = logic(pos[0][0], pos[0][1], pos[1][0], pos[1][1]);
    printf("%d\n", answer);
}

