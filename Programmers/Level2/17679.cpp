/* [1차] 프렌즈4블록 */

#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0, prev = -1, i, j, k, cnt = 0;
    int arr[30][1000] = {};

    while (answer != prev) {
        prev = answer;
        
        for (i = m - 1; i > 0; --i) {
            for (j = 0; j < n - 1; ++j) {
                if (board[i][j] == '-' || board[i][j] != board[i - 1][j] || board[i][j] != board[i][j + 1] || board[i][j] != board[i - 1][j + 1]) continue;
                arr[i - 1][j] = arr[i][j] + 1;
                arr[i - 1][j + 1] = arr[i][j + 1] + 1;
            }
        }
        
        for (j = 0; j < n; ++j) {
            for (i = 0; i < m - 1; ++i) {
                if (cnt) {
                    arr[i][j] = 0;
                    --cnt;
                } else if (arr[i][j]) {
                    for (k = i + arr[i][j]; k >= 0 && board[k][j] != '-'; --k) {
                        if (k - arr[i][j] - 1 < 0) board[k][j] = '-';
                        else board[k][j] = board[k - arr[i][j] - 1][j];
                    }
                    answer += arr[i][j] + 1;
                    cnt = arr[i][j] - 1;
                    arr[i][j] = 0;
                }
            }
        }
    }
    
    return answer;
}