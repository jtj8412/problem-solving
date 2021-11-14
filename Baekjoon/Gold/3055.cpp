//----------------------------------------------------------------------------------
// [ 탈출 ] https://www.acmicpc.net/problem/3055
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

struct DATA { int x, y; };

const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int W, H;

void water_logic(queue<DATA>& q, string* board) {
    int size = q.size();
    while (size-- > 0) {
        DATA cur = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            if (nx < 0 || ny < 0 || nx >= W || ny >= H || (board[ny][nx] != '-' && board[ny][nx] != '.')) continue;
            board[ny][nx] = '*';
            q.push(DATA({nx, ny}));
        }
    }
}

int logic() {
    int dest_x, dest_y, size = 1, cnt = 0, answer = 1;
    string board[50];
    queue<DATA> water_q, q;
    scanf("%d %d\n", &H, &W);
    for (int i = 0; i < H; ++i) {
        cin >> board[i];
        for (int j = 0; j < W; ++j) {
            if (board[i][j] == 'D') { dest_x = j; dest_y = i; }
            else if (board[i][j] == 'S') q.push(DATA({j, i}));
            else if (board[i][j] == '*') water_q.push(DATA({j, i}));
        }
    }
    board[q.front().y][q.front().x] = '-';
    while (!q.empty()) {
        DATA cur = q.front(); q.pop();
        if (board[cur.y][cur.x] != '*') {
            for (int i = 0; i < 4; ++i) {
                int nx = cur.x + dx[i], ny = cur.y + dy[i];
                if (nx < 0 || ny < 0 || nx >= W || ny >= H || (board[ny][nx] != 'D' && board[ny][nx] != '.')) continue;
                if (board[ny][nx] == 'D') return answer;
                board[ny][nx] = '-';
                q.push(DATA({nx, ny}));
            }
        }
        if (++cnt == size) {
            cnt = 0;
            size = q.size();
            answer++;
            water_logic(water_q, board);
        }
    }
    return 0;
}

int main() {
    int ret = logic();
    if (ret) cout << ret;
    else cout << "KAKTUS";
}