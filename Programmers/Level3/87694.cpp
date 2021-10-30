//----------------------------------------------------------------------------------
// [ 아이템 줍기 ] https://programmers.co.kr/learn/courses/30/lessons/87694
//
// 2차원 배열 board를 만들고 사각형 둘레에 맞게 맵을 그립니다.
// 단, 도형 간의 간격이 1인 경우 탐색에 여러 조건이 붙어야할 수 있으므로 맵을 2배로 확장시킵니다.
// 맵에 그려진 사각형 둘레에 따라 탐색을 진행합니다.
// 진행하려는 경로가 어떠한 사각형 안에 있는 경로일 경우 다른 방향을 탐색합니다.
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

#define REC(y, x) ((*pRec)[y][x])
#define REC_SIZE (pRec->size())

vector<vector<int>>* pRec;
int answer = 0x7fffffff, board[102][102], destX, destY;
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

bool IsInnerSquare(int x, int y) {
    for (int i = 0; i < REC_SIZE; ++i) {
        if (x > REC(i, 0) && y > REC(i, 1) && x < REC(i, 2) && y < REC(i, 3)) return true;
    }
    return false;
}

void logic(int x, int y, int cnt) {
    if (x == destX && y == destY) {
        answer = min(answer, cnt);
        board[y][x] = 1;
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (board[ny][nx] && !IsInnerSquare(nx, ny)) {
            board[ny][nx] = 0;
            logic(nx, ny, cnt + 1);
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    pRec = &rectangle;
    destX = itemX * 2, destY= itemY * 2;
    characterX *= 2; characterY *= 2;

    for (int i = 0; i < rectangle.size(); ++i) {
        for (int j = 0; j < 4; ++j) rectangle[i][j] *= 2;
    }

    for (int i = 0; i < rectangle.size(); ++i) {
        for (int x = rectangle[i][0]; x <= rectangle[i][2]; ++x) {
            board[rectangle[i][1]][x] = board[rectangle[i][3]][x] = 1;
        }

        for (int y = rectangle[i][1]; y <= rectangle[i][3]; ++y) {
            board[y][rectangle[i][0]] = board[y][rectangle[i][2]] = 1;
        }
    }

    board[characterY][characterX] = 0;
    logic(characterX, characterY, 0);
    
    return answer / 2;
}