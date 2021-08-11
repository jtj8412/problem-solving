//----------------------------------------------------------------------------------
// [ 크레인 인형뽑기 게임 ] https://programmers.co.kr/learn/courses/30/lessons/64061
//
// 1. x축별로 가장 위의 y좌표 저장 (top_pos)
// 2. moves에서 뽑을 인형의 x좌표를 획득하고, top_pos[x]를 통해 y좌표를 구한다
// 3. 쌓으려는 인형과 바구니 상단에 위치한 인형이 같은 경우 두 인형을 제거한다
// 4. 3에 부적합할 경우 바구니에 인형을 추가한다
// 5. 3에서 제거된 인형의 개수 합이 정답
//----------------------------------------------------------------------------------

#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0, top_pos[30], i, j, N = board.size();
    stack<int> stk;

    fill_n(top_pos, N, N);
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            if (board[j][i]) {
                top_pos[i] = j;
                break;
            }
        }
    }

    for (auto x : moves) {
        if (top_pos[--x] == N) continue;
        if (!stk.empty() && stk.top() == board[top_pos[x]][x]) {
            stk.pop();
            answer += 2;
        } else {
            stk.push(board[top_pos[x]][x]);
        }
        ++top_pos[x];
    }

    return answer;
}