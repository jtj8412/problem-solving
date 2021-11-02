//----------------------------------------------------------------------------------
// [ 2048 (Easy) ] https://www.acmicpc.net/problem/12100
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int N, start_board[20][20], board[20][20], answer = 0, testcase[5];

void logic(int idx) {
    int endval, endidx, cur;

    switch (testcase[idx]) {
    case 0:
        for (int i = 0; i < N; ++i) {
            endval = -1, endidx = -1;
            for (int j = 0; j < N; ++j) {
                cur = board[i][j];
                if (cur != 0) {
                    if (endval == cur) {
                        board[i][j] = 0;
                        board[i][endidx] = cur * 2;
                        answer = max(answer, cur * 2);
                        endval = -1;
                    } else {
                        endidx++;
                        board[i][j] = 0;
                        board[i][endidx] = cur;
                        endval = cur;
                    }
                }
            }
        }
        break;
    case 1:
        for (int i = 0; i < N; ++i) {
            endval = -1, endidx = N;
            for (int j = N - 1; j >= 0; --j) {
                cur = board[i][j];
                if (cur != 0) {
                    if (endval == cur) {
                        board[i][j] = 0;
                        board[i][endidx] = cur * 2;
                        answer = max(answer, cur * 2);
                        endval = -1;
                    } else {
                        endidx--;
                        board[i][j] = 0;
                        board[i][endidx] = cur;
                        endval = cur;
                    }
                }
            }
        }
        break;
    case 2:
        for (int i = 0; i < N; ++i) {
            endval = -1, endidx = -1;
            for (int j = 0; j < N; ++j) {
                cur = board[j][i];
                if (cur != 0) {
                    if (endval == cur) {
                        board[j][i] = 0;
                        board[endidx][i] = cur * 2;
                        answer = max(answer, cur * 2);
                        endval = -1;
                    } else {
                        endidx++;
                        board[j][i] = 0;
                        board[endidx][i] = cur;
                        endval = cur;
                    }
                }
            }
        }
        break;
    case 3:
        for (int i = 0; i < N; ++i) {
            endval = -1, endidx = N;
            for (int j = N - 1; j >= 0; --j) {
                cur = board[j][i];
                if (cur != 0) {
                    if (endval == cur) {
                        board[j][i] = 0;
                        board[endidx][i] = cur * 2;
                        answer = max(answer, cur * 2);
                        endval = -1;
                    } else {
                        endidx--;
                        board[j][i] = 0;
                        board[endidx][i] = cur;
                        endval = cur;
                    }
                }
            }
        }
        break;
    }
    
    if (idx != 4) logic(idx + 1);
}

void makecase(int idx) {
    if (idx == 5) {
        memcpy(board, start_board, sizeof(int) * 400);
        logic(0);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        testcase[idx] = i;
        makecase(idx + 1);
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
        scanf("%d", &start_board[i][j]);
        answer = max(answer, start_board[i][j]);
    }
    makecase(0);
    printf("%d", answer);
}