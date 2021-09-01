//----------------------------------------------------------------------------------
// [ 카드 짝 맞추기 ] https://programmers.co.kr/learn/courses/30/lessons/72415
//
// 카드 번호를 (n - 1) * 2 + (0 or 1) 로 재해석 (ex: 1->0,1  2->2,3  3->4,5)
// 카드 a에서 카드 b로 가기 위한 최소 입력 값을 캐싱하는 g_cache[a][b][c] 선언 
// (c는 제거된 카드를 비트마스크로 표현)
// 1. board 해석
//   1-1. card_pos에 카드 번호에 따른 위치(x, y) 저장
//   1-2. board에 적힌 카드 번호를 비트 마스크로 변경 (탐색 시 제거된 카드인지 판단하기 위해)
//   1-3. 총 카드 갯수 저장 (Enter 입력 횟수와 같음)
// 2. pmu[1,2,3,4,5,6] 을 순열을 이용해 정렬
//    pmu[0]번 카드 -> pmu[1]번 카드 -> pmu[2]번 카드 ... 제거되는 카드 순서의 경우로써 사용
// 3. 2번에서 뽑은 순열의 모든 경우의 수를 가지고 시뮬레이션
//    이전 카드 위치 -> 제거하려는 카드로 이동 (같은 번호 중 중 하나) -> 나머지 같은 번호 카드로 이동 
//    이를 재귀 방식으로 구현
// 4. 카드 c(비트 마스크)가 제거되었을 때 카드 a에서 카드 b로 가기 위한 최단 경로 move(a,b,c)
//   4-1. 캐싱되어있는 값이 있을 경우 해당 값 리턴
//   4-2. 이중 for문을 이용하여 카드 a에서 카드 b까지 board 탐색
//   4-3. 탐색중인 board를 기준으로 카드 b로 가기 위한 x방향, y방향 각각 한 칸 앞의 입력값 계산 (현재 위치 + 1)
//   4-4. 4-3에서 벽면이나 카드 위일 경우 이전 지점에서 Ctrl+이동 으로 해당 지점까지 올 수 있는 지점의 최솟값 + 1
//   4-5. 결괏값을 캐싱
// 5. 3,4의 결과로 정답을 도출
//----------------------------------------------------------------------------------

#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define BOARD(y,x) ((*pBoard)[y][x])
#define IS_PASS(y,x,ignore_mask) (!BOARD(y,x) || (BOARD(y,x) & ignore_mask))

const int INF = 0x7fffffff;
// a번째 카드 위치에서 b번째 카드 위치로 가기 위한 최소 입력 값 (c는 제거된 카드를 비트 마스크로 표현)
int g_cache[13][12][1 << 6];
pair<int,int> card_pos[13];
vector<vector<int>> *pBoard;

// ignore_mask의 카드들을 무시하고 카드1(card_from) 에서 카드2(card_to) 까지 이동하기 위한 최소 입력값
int move(int card_from, int card_to, int ignore_mask) {
    pair<int, int>  from = card_pos[card_from], to = card_pos[card_to];
    int dx = ((to.first - from.first) == 0 ? 0 : (to.first - from.first) / abs(to.first - from.first)),
        dy = ((to.second - from.second) == 0 ? 0 : (to.second - from.second) / abs(to.second - from.second)),
        i, j, k, x, y, next_x, next_y;
    int cache[4][4];
    
    if (g_cache[card_from][card_to][ignore_mask] != -1) return g_cache[card_from][card_to][ignore_mask];

    fill((int*)cache, (int*)cache + 16, INF);
    cache[from.second][from.first] = 0;

    for (i = 0; i <= abs(from.second - to.second); ++i) {
        y = from.second + (dy * i); next_y = y + dy;
        for (j = 0; j <= abs(from.first - to.first); ++j) {
            x = from.first + (dx * j); next_x = x + dx; 
            
            if (next_x >= 0 && next_x < 4 && x != to.first) {
                if (IS_PASS(y, next_x, ignore_mask) && next_x != 0 && next_x != 3) {
                    cache[y][next_x] = min(cache[y][next_x], cache[y][x] + 1);
                } else {
                    for (k = x; k != from.first - dx && IS_PASS(y, k, ignore_mask); k -= dx)
                        cache[y][next_x] = min(cache[y][next_x], cache[y][k] + 1);
                    if (k != from.first - dx) cache[y][next_x] = min(cache[y][next_x], cache[y][k] + 1);
                }
            }

            if (next_y >= 0 && next_y < 4 && y != to.second) {
                if (IS_PASS(next_y, x, ignore_mask) && next_y != 0 && next_y != 3) {
                    cache[next_y][x] = min(cache[next_y][x], cache[y][x] + 1);                    
                } else {
                    for (k = y; k != from.second - dy && IS_PASS(k, x, ignore_mask); k -= dy)
                        cache[next_y][x] = min(cache[next_y][x], cache[k][x] + 1);
                    if (k != from.second - dy) cache[next_y][x] = min(cache[next_y][x], cache[k][x] + 1);
                }
            }
        }
    }
    g_cache[card_from][card_to][ignore_mask] = cache[to.second][to.first];
    return cache[to.second][to.first];
}

int search(vector<int> &pmu, int prev_card = 12, int idx = 0, int visited = 0) {
    if (idx == pmu.size()) return 0;

    int next_card = pmu[idx] << 1, next_card2 = (pmu[idx] << 1) | 1, next_visited = visited | (1 << (pmu[idx]));

    return min(move(prev_card, next_card, visited) + move(next_card, next_card2, visited) + search(pmu, next_card2, idx + 1, next_visited),
        move(prev_card, next_card2, visited) + move(next_card2, next_card, visited) + search(pmu, next_card, idx + 1, next_visited));
}

int solution(vector<vector<int>> board, int r, int c) {
    vector<int> pmu;
    int answer = INF, card_cnt = 0, i, j;

    pBoard = &board;
    for (i = 0; i < 13; ++i) card_pos[i].first = -1;
    card_pos[12] = make_pair(c,r);
    fill((int*)g_cache, (int*)g_cache + (13*12*(1<<6)), -1);

    // 카드 위치 및 갯수 저장, board의 카드 번호를 비트 마스크로 변경
    for (i = 0; i < 4; ++i) for (j = 0; j < 4; ++j) {
        if (!board[i][j]) continue;
        if (card_pos[(board[i][j] - 1) << 1].first == -1) card_pos[(board[i][j] - 1) << 1] = make_pair(j, i);
        else card_pos[(board[i][j] - 1) << 1 | 1] = make_pair(j, i);
        board[i][j] = (1 << (board[i][j] - 1));
        ++card_cnt;
    }

    for (i = 0; i < (card_cnt >> 1); ++i) pmu.push_back(i);
    do { answer = min(answer, search(pmu)); } while (next_permutation(pmu.begin(), pmu.end()));
    
    return answer + card_cnt;
}