/* 크레인 인형뽑기 게임 */

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> stk;
    int N = board.size();

    for (int i = 0; i < moves.size(); ++i) {
        int move = moves[i];
        for (int j = 0; j < N; ++j) {
            int& block = board[j][move - 1];
            if (block != 0) {
                if (stk.size() != 0 && stk.top() == block) {
                    stk.pop();
                    answer += 2;
                }
                else {
                    stk.push(block);
                }
                block = 0;
                break;
            }
        }
    }

    return answer;
}