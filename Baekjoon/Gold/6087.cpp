//----------------------------------------------------------------------------------
// [ 레이저 통신 ] https://www.acmicpc.net/problem/6087
//
// 해당 위치 방문 여부를 기록하는 visited 변수에 추가로 방문했을 때의 방향을 기록하기 위해
// 한 차원을 더 추가하는 방법
// visited[y][x][dir]
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

struct DATA { int x, y, dir, cnt; };

int W, H, visited[100][100][4] = {}, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
string board[100];
vector<DATA> laser;

int logic() {
    int answer = 0x7fffffff;
    queue<DATA> q;
    for (int i = 0; i < 4; ++i) {
        q.push(DATA({laser[0].x, laser[0].y, i, 0}));
        visited[laser[0].y][laser[0].x][i] = 1;
    }
    while (!q.empty()) {
        DATA cur = q.front(); q.pop();
        if (visited[cur.y][cur.x][cur.dir] <= cur.cnt) continue;
        for (int i = 0; i < 4; ++i) {
            DATA next = {cur.x + dx[i], cur.y + dy[i], i, cur.cnt + ((cur.dir != i) ? 1 : 0)};
            if (next.x < 0 || next.y < 0 || next.x >= W || next.y >= H || board[next.y][next.x] == '*' || visited[next.y][next.x][next.dir] <= next.cnt + 1) continue;
            visited[next.y][next.x][next.dir] = next.cnt + 1;
            if (next.x == laser[1].x && next.y == laser[1].y) answer = min(answer, next.cnt);
            else q.push(next);
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> W >> H;
    fill((int*)(visited), (int*)(visited) + 40000, 0x7fffffff);
    for (int i = 0; i < H; ++i) {
        cin >> board[i];
        for (int j = 0; j < W; ++j) {
            if (board[i][j] == 'C') laser.push_back(DATA({j, i}));
        }
    }
    cout << logic() << endl;
}