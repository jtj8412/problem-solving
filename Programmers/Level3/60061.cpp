//----------------------------------------------------------------------------------
// [ 기둥과 보 설치 ] https://programmers.co.kr/learn/courses/30/lessons/60061
//----------------------------------------------------------------------------------

#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_vec) {
    vector<vector<int>> answer;
    int board[101][101][3] = {}, build_size = build_vec.size(),
        x, y, i, j;

    for (i = 0; i < build_size; ++i) {
        x = build_vec[i][0]; y = build_vec[i][1];
        if (!build_vec[i][2]) {
            if (build_vec[i][3]) {      // 기둥 설치
                if (y == 0 || board[y-1][x][0] || board[y][x][1]) board[y][x][0] = 1;
            } else {                    // 기둥 삭제
                if (board[y][x][0] && (!board[y+1][x][0] || board[y+1][x][1]) &&
                    (!board[y+1][x][2] || (board[y+1][x][1] == 2 && board[y+1][x+1][1] == 2) || board[y][x+1][0]) &&
                    (!board[y+1][x-1][2] || (board[y+1][x-1][1] == 2 && board[y+1][x][1] == 2) || board[y][x-1][0])) 
                    board[y][x][0] = 0;
            }
        } else {
            if (build_vec[i][3]) {      // 보 설치
                if (board[y-1][x][0] || board[y-1][x+1][0] || (board[y][x][1] && board[y][x+1][1])) 
                { board[y][x][1]++; board[y][x+1][1]++; board[y][x][2] = 1;}
            } else {                    // 보 삭제
                if (board[y][x][2] &&
                    (!board[y][x][0] || board[y][x][1] == 2 || board[y-1][x][0]) &&
                    (!board[y][x+1][0] || board[y][x+1][1] == 2 || board[y-1][x+1][0]) &&
                    (board[y][x][1] == 1 || board[y-1][x-1][0] || board[y-1][x][0]) &&
                    (board[y][x+1][1] == 1 || board[y-1][x+1][0] || board[y-1][x+2][0])) 
                    { board[y][x][1]--; board[y][x+1][1]--; board[y][x][2] = 0;}
            }
        }
    }
    
    for (i = 0; i <= n; ++i) {
        for (j = 0; j <= n; ++j) {
            if (board[j][i][0]) answer.push_back({i,j,0});
            if (board[j][i][2]) answer.push_back({i,j,1});
        }
    }

    return answer;
}