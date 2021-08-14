//----------------------------------------------------------------------------------
// [ 블록 이동하기 ] https://programmers.co.kr/learn/courses/30/lessons/60063
//
// 로봇이 가로로 배치되었을때 위치(x,y)는 우측날개 기준으로, 방향(dir)은 0으로 설정
// 로봇이 세로로 배치되었을때 위치(x,y)는 하단날개 기준으로, 방향(dir)은 1으로 설정
// 처음 위치를 시작으로, 이동할 수 있는 가능성(x,y,dir) 및 몇 번째 이동(cnt)인지 큐에 하나씩 넣고 뺀다
// 같은 방향, 같은 위치로의 이동은 저장해두었다가 재방문을 금지한다 (visited[y][x][dir])
// 큐에서 뺀 위치가 (N-1, N-1)일 경우 종료하며, 해당 데이터의 cnt값이 정답
//----------------------------------------------------------------------------------

#include <vector>
#include <queue>
using namespace std;

struct DATA { int x, y, dir, cnt; };

int visited[100][100][2] = {};
queue<DATA> q;

void move(int x, int y, int dir, int cnt, vector<vector<int>> &board) {
    if (visited[y][x][dir]) return;
    visited[y][x][dir] = 1;
    q.push(DATA({x, y, dir, cnt+1}));
}

int solution(vector<vector<int>> board) {
    int n = board.size();

    visited[0][1][0] = 1;
    q.push(DATA({1,0,0,0}));

    while (q.front().x != n - 1 || q.front().y != n - 1) {
        DATA data = q.front(); q.pop();
        if (data.dir == 0) {
            if (data.x > 1 && !board[data.y][data.x-2]) 
                move(data.x-1, data.y, 0, data.cnt, board);
            if (data.x < n-1 && !board[data.y][data.x+1]) 
                move(data.x+1, data.y, 0, data.cnt, board);
            if (data.y > 0 && !board[data.y-1][data.x] && !board[data.y-1][data.x-1]) {
                move(data.x, data.y-1, 0, data.cnt, board);
                move(data.x, data.y, 1, data.cnt, board);
                move(data.x-1, data.y, 1, data.cnt, board);
            }
            if (data.y < n-1 && !board[data.y+1][data.x] && !board[data.y+1][data.x-1]) {
                move(data.x, data.y+1, 0, data.cnt, board);
                move(data.x, data.y+1, 1, data.cnt, board);
                move(data.x-1, data.y+1, 1, data.cnt, board);
            }
        } else {
            if (data.x > 0 && !board[data.y][data.x-1] && !board[data.y-1][data.x-1]) {
                move(data.x-1, data.y, 1, data.cnt, board);
                move(data.x, data.y-1, 0, data.cnt, board);
                move(data.x, data.y, 0, data.cnt, board);
            }
            if (data.x < n-1 && !board[data.y][data.x+1] && !board[data.y-1][data.x+1]) {
                move(data.x+1, data.y, 1, data.cnt, board);
                move(data.x+1, data.y-1, 0, data.cnt, board);
                move(data.x+1, data.y, 0, data.cnt, board);
            }
            if (data.y > 1 && !board[data.y-2][data.x]) 
                move(data.x, data.y-1, 1, data.cnt, board);
            if (data.y < n-1 && !board[data.y+1][data.x]) 
                move(data.x, data.y+1, 1, data.cnt, board);
        }
    }
    return q.front().cnt;
}