//----------------------------------------------------------------------------------
// [ 테트로미노 ] https://www.acmicpc.net/problem/14500
//----------------------------------------------------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int answer = 0, N, M;

void dfs(int cnt, int sum, int len, int x, int y, const vector<vector<int>>& board) {
    if (cnt == 4 || y == N){
        answer = max(answer, sum);        
        return;
    }
    for (int i = 1; i <= 4 - cnt; ++i) {
        for (int j = x - i + 1; j < x + len; ++j) {
            if (j < 0 || j + i > M) continue;
            int val = 0;
            for (int k = 0; k < i; ++k)
                val += board[y][j + k];
            dfs(cnt + i, sum + val, i, j, y + 1, board);
        }
    }
}

int main() {
    vector<vector<int>> board;
    int val;
    scanf("%d %d", &N, &M);
    board.resize(N);
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
        scanf("%d", &val);
        board[i].push_back(val);
    }
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) dfs(0, 0, 1, j, i, board);
    printf("%d\n", answer);
}