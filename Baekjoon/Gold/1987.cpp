//----------------------------------------------------------------------------------
// [ 알파벳 ] https://www.acmicpc.net/problem/1987
//----------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
string board[20];
int R, C, answer = 0, visited[20][20] = {};

void dfs(int x, int y, int val, int cache) {
    answer = max(answer, val);

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= C || ny < 0 || ny >= R || visited[ny][nx] || (cache & (1 << board[ny][nx]))) continue;
        visited[ny][nx] = 1;
        dfs(nx, ny, val + 1, cache | (1 << board[ny][nx]));
        visited[ny][nx] = 0;
    }
}

int main() {
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; ++i) cin >> board[i];
    visited[0][0] = 1;
    dfs(0, 0, 1, (1 << board[0][0]));
    printf("%d\n", answer);
}