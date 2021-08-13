//----------------------------------------------------------------------------------
// [ 리틀 프렌즈 사천성 ] https://programmers.co.kr/learn/courses/30/lessons/1836
//
// 1. 알파벳의 오름차순으로 타일 위치 및 알파벳 저장 (vec)
// 2. a1타일 -> a2타일 연결 가능 루트는 수평이동->수직이동 또는 수직이동->수평이동이며
//    연결가능시, 두 타일을 저장소에서(board, vec) 제거 및 answer에 타일 알파벳 추가
// 3-1. 모든 타일을 제거했을때(empty) 정답: answer
// 3-2. 타일 제거가 더이상 되지 않을때(prev_size == size) 정답: "IMPOSSIBLE"
//----------------------------------------------------------------------------------

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct DATA { 
    int ch, x1, x2, y1, y2; 
    DATA(int ch, int x1, int y1): ch(ch), x1(x1), y1(y1) {}
    bool operator==(int ch) { return this->ch == ch;}
};

bool move_x(int x, int y,  int dx, int dest_x, int ch, vector<string> &board) {
    int i;
    for (i = x + dx; i != dest_x && board[y][i] == '.'; i += dx);
    return (i == dest_x && (board[y][i]=='.' || board[y][i]==ch )) ? true : false;
}

bool move_y(int x, int y,  int dy, int dest_y, int ch, vector<string> &board) {
    int i;
    for (i = y + dy; i != dest_y && board[i][x] == '.'; i += dy);
    return (i == dest_y && (board[i][x]=='.' || board[i][x]==ch )) ? true : false;
}

string solution(int m, int n, vector<string> board) {
    string answer = "";
    vector<DATA> vec;
    vector<DATA>::iterator iter;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            char ch = board[i][j];
            if (ch == '.' || ch == '*') continue;
            iter = find(vec.begin(), vec.end(), ch);
            if (iter == vec.end()) vec.push_back(DATA(ch, j, i));
            else { iter->x2 = j; iter->y2 = i;}
        }
    }

    sort(vec.begin(), vec.end(), [](const DATA& a, const DATA& b)->bool{return a.ch < b.ch;});

    while (!vec.empty()) {
        int prev_size = vec.size();
        for (int i = 0; i < vec.size(); ++i) {
            int dx = (vec[i].x1 == vec[i].x2) ? 0 : -(vec[i].x1 - vec[i].x2) / abs(vec[i].x1 - vec[i].x2);
            int dy = (vec[i].y1 == vec[i].y2) ? 0 : -(vec[i].y1 - vec[i].y2) / abs(vec[i].y1 - vec[i].y2);
            if ( (dx && move_x(vec[i].x1, vec[i].y1, dx, vec[i].x2, vec[i].ch, board) && (!dy ||move_y(vec[i].x2, vec[i].y1, dy, vec[i].y2, vec[i].ch, board))) ||
                (dy && move_y(vec[i].x1, vec[i].y1, dy, vec[i].y2, vec[i].ch, board) && (!dx || move_x(vec[i].x1, vec[i].y2, dx, vec[i].x2, vec[i].ch, board)))) {
                board[vec[i].y1][vec[i].x1] = board[vec[i].y2][vec[i].x2] = '.';
                answer += vec[i].ch;
                vec.erase(vec.begin() + i);
                break;
            }
        }
        if (prev_size == vec.size()) return "IMPOSSIBLE";
    }

    return answer;
}