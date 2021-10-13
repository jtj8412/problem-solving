//----------------------------------------------------------------------------------
// [ 미로 탐색 ] https://www.acmicpc.net/problem/2178
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int N, M, dx[] = {0,0,-1,1}, dy[] = {-1,1,0,0}, board[100][100];

void bfs() {
    queue<pair<int,int>> q;

    q.push(make_pair(0, 0));

    while (!q.empty()) {
        pair<int, int> pos = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = pos.first + dx[i], ny = pos.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= M || ny >= N || board[ny][nx] == 0 || board[ny][nx] > 1) continue;
            board[ny][nx] = board[pos.second][pos.first] + 1;
            if (ny == M - 1 && nx == N - 1) return;
            q.push(make_pair(nx, ny));
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);  
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
        scanf("%1d", &board[i][j]);
    }
    bfs();
    printf("%d\n", board[N-1][M-1]);
}

