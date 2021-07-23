/* 가장 큰 정사각형 찾기 */

#include <vector>

int maximum(int a, int b) { return (a > b) ? a : b; }
int minimum(int a, int b, int c) { return (a < b) ? ((c < a) ? c : a) : ((c < b) ? c : b); }

int solution(std::vector<std::vector<int>> board)
{
    int answer = 0,
        h = board.size(),
        w = board[0].size(),
        i, j, m;
    
    for (i = 0; i < w; ++i) answer = maximum(answer, board[0][i]);
    for (i = 0; i < h; ++i) answer = maximum(answer, board[i][0]);

    for (i = 1; i < h; ++i) {
        for (j = 1; j < w; ++j) {
            if (!board[i][j] || (m = minimum(board[i][j - 1], board[i - 1][j], board[i - 1][j - 1])) == 0) continue;
            board[i][j] = m + 1;
            answer = maximum(board[i][j], answer);
        }
    }

    return answer * answer;
}