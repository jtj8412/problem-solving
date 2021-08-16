//----------------------------------------------------------------------------------
// [ 위클리 챌린지 3주차 ] https://programmers.co.kr/learn/courses/30/lessons/84021
//
// 1. game_board, table를 bfs 탐색 : search_board
//   1-1. game_board의 빈 도형, table의 조각 도형의 좌표 리스트를 blank_vec, piece_vec에 저장한다
//   1-2. 좌표를 저장할 때 각 도형을 [6][6] 배열의 좌상단에 위치시켰을 때의 좌표를 저장한다
//   1-3. 도형을 이루는 요소 갯수가 같은 것 끼리 비교하기 위해 좌표 리스트의 배열을 만든다 (blank_vec, piece_vec [0~5])
//   1-4. 원활한 비교를 위해 도형을 이루는 요소들의 좌표를 오름차순으로 정렬한다
// 2. blank_vec의 빈 도형과 piece_vec의 조각이 일치하는지 확인한다 : fill_blank
//   2-1. 동일한 인덱스의 좌표를 비교했을 때 모두 같을 경우 빈 칸에 도형을 체울 수 있다
//   2-2. 체워진 빈 칸과 사용된 도형 정보는 리스트(blank_vec, piece_vec)에서 삭제한다
// 3. piece_vec에서 남은 조각들을 시계방향으로 90도 회전한다 : rotate_pieces
//   3-1. 좌표 정보가 [6][6] 배열을 기준으로 되어있으므로 90도 회전시 x=y-5, y=x 이다
//   3-2. 회전 후 좌상단으로 재위치시키고 좌표를 오름차순으로 정렬한다
// 4. 2와 3의 반복 결과 도출된 answer가 정답이다 
//----------------------------------------------------------------------------------

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

int visited[50][50] = {}, dx[] = {0,0,-1,1}, dy[] = {-1,1,0,0}, N, answer = 0;
vector<vector<pair<int,int>>> blank_vec[6], piece_vec[6];

bool lower_position(const pair<int,int> &a, const pair<int,int> &b) {
    return (a.second == b.second) ? a.first < b.first : a.second < b.second;
}

void search_board(vector<vector<int>> &board, vector<vector<pair<int,int>>> dest[], int val) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] != val || visited[i][j]) continue;
            queue<pair<int,int>> q;
            vector<pair<int,int>> data;
            int next_x, next_y, shift, min_x = j;
            data.push_back(make_pair(j,0));
            visited[i][j] = 1;
            q.push(make_pair(j, i));
            while (!q.empty()) {
                for (int k = 0; k < 4; ++k) {
                    next_x = q.front().first + dx[k]; next_y = q.front().second + dy[k];
                    if (next_x < 0 || next_y < 0 || next_x == N || next_y == N || board[next_y][next_x] != val || visited[next_y][next_x]) continue;
                    visited[next_y][next_x] = 1;
                    if (next_x < min_x) min_x = next_x;
                    data.push_back(make_pair(next_x, next_y - i));
                    q.push(make_pair(next_x, next_y));
                }
                q.pop();
            }
            for (int i = 0; i < data.size(); ++i) data[i].first -= min_x;
            sort(data.begin(), data.end(), lower_position);
            dest[data.size()-1].push_back(data);
        }
    }
}

bool check_fill(const vector<pair<int,int>> &a, const vector<pair<int,int>> &b) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i].first != b[i].first || a[i].second != b[i].second) return false;
    }
    return true;
}

void fill_blank() {
    for (int i = 0; i < 6; ++i) {
        if (blank_vec[i].empty()) continue;
        for (int j = blank_vec[i].size() - 1; j >= 0; --j) {
            for (int k = piece_vec[i].size() - 1; k >= 0; --k) {
                if (!check_fill(blank_vec[i][j], piece_vec[i][k])) continue;
                answer += i + 1;
                blank_vec[i].erase(blank_vec[i].begin() + j);
                piece_vec[i].erase(piece_vec[i].begin() + k);
                break;
            }
        }
    }
}

void rotate_pieces() {
    for (int i = 0; i < 6; ++i) {
        if (blank_vec[i].empty()) continue;
        for (int j = 0; j < piece_vec[i].size(); ++j) {
            int min_y = 6, min_x = 6;
            for (int k = 0; k < piece_vec[i][j].size(); ++k) {
                int x = piece_vec[i][j][k].first, y = piece_vec[i][j][k].second;
                piece_vec[i][j][k].first = 5 - y;
                piece_vec[i][j][k].second = x;
                if (5-y < min_x) min_x = 5-y;
                if (x < min_y) min_y = x;
            }
            for (int k = 0; k < piece_vec[i][j].size(); ++k) {
                piece_vec[i][j][k].first -= min_x;
                piece_vec[i][j][k].second -= min_y;
            }
            sort(piece_vec[i][j].begin(), piece_vec[i][j].end(), lower_position);
        }
    }
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    N = table.size();
    search_board(game_board, blank_vec, 0);
    memset((int*)visited, 0, 10000);
    search_board(table, piece_vec, 1);
    fill_blank();
    for (int i = 0; i < 3; ++i) {
        rotate_pieces();
        fill_blank();
    }
    return answer;
}