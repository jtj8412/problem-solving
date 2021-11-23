//----------------------------------------------------------------------------------
// [ 적록색약 ] https://www.acmicpc.net/problem/14395
//
// DFS 방식으로 탐색을 하고 그 내부는 BFS 로직을 사용
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

struct DATA { int x, y; };

const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int N, rg = 0, red = 0, green = 0, blue = 0, visited[100][100] = {};
string board[100];

void logic(int x, int y) {
    queue<DATA> q, next_q;
    if (board[y][x] == 'R') {rg++; red++;}
    else if (board[y][x] == 'G') {rg++; green++;}
    else blue++;
    q.push(DATA({x, y}));
    visited[y][x] = 1;
    while (!q.empty()) {
        DATA cur = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            DATA next = {cur.x + dx[i], cur.y + dy[i]};
            if (next.x < 0 || next.y < 0 || next.x >= N || next.y >= N || visited[next.y][next.x]) continue;
            if (board[y][x] != board[next.y][next.x]) {
                if (abs(board[y][x] - board[next.y][next.x]) == 11) next_q.push(DATA{next.x, next.y});
            } else {
                visited[next.y][next.x] = 1;
                q.push(DATA({next.x, next.y}));
            }
        }
    }
    while (!next_q.empty()) {
        DATA cur = next_q.front(); next_q.pop();
        if (visited[cur.y][cur.x]) continue;
        rg--;
        logic(cur.x, cur.y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> board[i];
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
        if (!visited[i][j]) logic(j, i);
    }
    cout << red + green + blue << " " << rg + blue;
}
