#include <vector>
using namespace std;

int map[1001][1001] = {};

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0, h = board.size(), w = board[0].size();
    
    for (int i = 0; i < skill.size(); ++i) {
        int val = (skill[i][0] == 1) ? -skill[i][5] : skill[i][5];
        int r1 = skill[i][1], c1 = skill[i][2], r2 = skill[i][3], c2 = skill[i][4];
        map[r1][c1] += val;
        map[r2 + 1][c1] += -val;
        map[r1][c2 + 1] += -val;
        map[r2 + 1][c2 + 1] += val;
    }

    for (int x = 0; x < w; ++x) {
        int val = 0;
        for (int y = 0; y < h; ++y) {
            map[y][x+1] += map[y][x];
            val += map[y][x];
            board[y][x] += val;
            if (board[y][x] > 0) ++answer;
        }
    }

    return answer;
}