//----------------------------------------------------------------------------------
// [ 경주로 건설 ] https://programmers.co.kr/learn/courses/30/lessons/67259
//
// cache에 도로 건설 위치(y,x), 현재 진행 방향(dir)에 따른 최소 비용(cost)을 담는다 (cache[y][x][dir])
// 1. bfs 방식으로 맵(board) 탐색한다. 만약 도로를 설치하려는 장소가 이미 설치가 되었던 장소라면
//    cache에 저장되어있는 비용과 현재 건설중인 비용을 비교할때 비용이 더 높을경우 무시된다.
// 2. 맵의 가장 끝(N-1, N-1)에 저장되어있는 cache 데이터가 정답이다
//----------------------------------------------------------------------------------

#include <vector>
#include <queue>
using namespace std;

struct DATA { int y, x, cost, dir; };
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int solution(vector<vector<int>> board) {
    int cache[25][25][2] = {}, i, x, y, dir, cost, N = board.size();
    queue<DATA> q;

    cache[0][0][0] = 1;
    cache[0][0][1] = 1;
    q.push(DATA({0,0,0,0}));
    q.push(DATA({0,0,0,1}));

    while (!q.empty()) {
        DATA& data = q.front();
        for (i = 0; i < 4; ++i) {
            x = data.x + dx[i]; y = data.y + dy[i];            
            if (x < 0 || y < 0 || x == N || y == N || board[y][x]) continue;
            dir = (i & 1) ? 1 : 0;
            cost = data.cost + ((dir == data.dir) ? 100 : 600);
            if (cache[y][x][dir] != 0 && cost >= cache[y][x][dir]) continue;
            cache[y][x][dir] = cost;
            q.push(DATA{y,x,cost,dir});
        }
        q.pop();
    }

    return (cache[N-1][N-1][0] == 0) ? cache[N-1][N-1][1] : ((cache[N-1][N-1][1] == 0) ? cache[N-1][N-1][0] : min(cache[N-1][N-1][0], cache[N-1][N-1][1]));
}