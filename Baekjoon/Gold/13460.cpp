//----------------------------------------------------------------------------------
// [ 구슬 탈출 2 ] https://www.acmicpc.net/problem/13460
//
// 백트래킹을 통해 가능한 모든 경우에 접근합니다.
// 4개의 선택지(상/하/좌/우)가 있으므로 시간 복잡도는 O(4^n)이며 최악의 경우 n이 10으로 
// 4^10 = 1,048,576번 순회해야합니다.
// 불필요한 경우를 없애기위해 지금까지 나온 정답의 최소 탐색 횟수보다
// 현재 탐색 횟수가 같거나 높으면 순회를 중지합니다.
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

struct DATA { 
    int x, y; 
    char ch;
    bool operator!=(const DATA& data) { return data.x != x || data.y != y; }
    bool operator==(const DATA& data) { return data.x == x && data.y == y; }
};

const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int N, M, answer = 0x7fffffff;
vector<string> board;   
DATA red, blue, hole;

int move(int d) {
    DATA* arr[] = {&red, &blue};
    int ret = 0;

    switch (d) {
    case 0:
        if (blue.x < red.x) swap(arr[0], arr[1]);
        break;
    case 1:
        if (blue.x > red.x) swap(arr[0], arr[1]);
        break;
    case 2:
        if (blue.y < red.y) swap(arr[0], arr[1]);
        break;
    case 3:
        if (blue.y > red.y) swap(arr[0], arr[1]);
        break;
    }
    
    for (int i = 0, nx, ny; i < 2; ++i) {
        board[arr[i]->y][arr[i]->x] = '.';
        for (nx = arr[i]->x + dx[d], ny = arr[i]->y + dy[d]; board[ny][nx] == '.'; nx += dx[d], ny += dy[d]);
        if (nx == hole.x && ny == hole.y) {
            ret |= (arr[i]->ch == 'R') ? 1 : 2;
        } else {
            arr[i]->x = nx - dx[d]; arr[i]->y = ny - dy[d];
            board[arr[i]->y][arr[i]->x] = arr[i]->ch;
        }
    }
    return ret;
}

void dfs(int cnt) {
    if (cnt == 11 || cnt >= answer) return;
    for (int i = 0; i < 4; ++i) {
        DATA prev_red = red, prev_blue = blue;

        int res = move(i);
        if (!res && (prev_red != red || prev_blue != blue)) {
            dfs(cnt + 1);
        }
        if (board[red.y][red.x] != 'O') board[red.y][red.x] = '.';
        if (board[blue.y][blue.x] != 'O') board[blue.y][blue.x] = '.';
        board[prev_red.y][prev_red.x] = 'R';
        board[prev_blue.y][prev_blue.x] = 'B';
        red = prev_red; blue = prev_blue;
        if (res == 1) {
            answer = min(answer, cnt);
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    board.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> board[i];
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == 'R') red = {j, i, 'R'};
            else if (board[i][j] == 'B') blue = {j, i, 'B'};
            else if (board[i][j] == 'O') hole = {j, i};
        }
    }
    dfs(1);
    if (answer == 0x7fffffff) answer = -1;
    printf("%d", answer);
}