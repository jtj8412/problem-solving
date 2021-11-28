//----------------------------------------------------------------------------------
// [ 별 찍기 - 10 ] https://www.acmicpc.net/problem/2447
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

vector<string> board;

void logic(int len) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if ((i == 0 && j == 0) || (i == 1 && j == 1)) continue;
            for (int ii = 0; ii < len; ++ii) {
                for (int jj = 0; jj < len; ++jj) {
                    board[i * len + ii][j * len + jj] = board[ii][jj];
                }
            }
        }
    }
}

int main() {
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    board.resize(n);
    for (int i = 0; i < n; ++i) {
        board[i].resize(n, ' ');
    }
    board[0][0] = board[0][1] = board[0][2] = board[1][0] = board[1][2] = board[2][0] = board[2][1] = board[2][2] = '*';
    for (int i = 3; i < n; i *= 3) {
        logic(i);
    }

    for (int i = 0; i < n; ++i) {
        cout << board[i] << "\n";
    }
}