//----------------------------------------------------------------------------------
// [ 순위 ] https://programmers.co.kr/learn/courses/30/lessons/49191
//
// 과거 경기 진행 여부를 나타내는 match_arr과, x 선수가 승리 및 패배하는 선수들의 리스트를
// 담은 match_vec을 선언한다. 
// match_vec[x][0]: x 선수가 승리하는 선수 리스트
// match_vec[x][1]: x 선수가 패배하는 선수 리스트
// 
// A 선수가 B 선수를 이길 경우
// - A 선수가 패배하는 선수들은 B 선수를 이기며, B 선수가 이기는 선수들에게 이긴다
// - B 선수가 이기는 선수들은 A 선수에게 패배하며, A 선수가 지는 선수들에게 진다
//
// 위의 조건을 가지고 match_vec을 완성했을 때, x 선수가 이기는 선수들의 수 + 지는 선수들의 수
// 즉 match_vec[x][0].size() + match_vec[x][1].size() 가 선수들 중 본인을 제외한 n - 1명일 때
// 정확하게 순위를 매길 수 있다고 판단한다
//----------------------------------------------------------------------------------

#include <vector>
using namespace std;

void match(int win, int lose, vector<int> match_vec[101][2], int match_arr[101][101]) {
    if (match_arr[win][lose]) return;
    match_arr[win][lose] = match_arr[lose][win] = 1;
    match_vec[win][0].push_back(lose);
    match_vec[lose][1].push_back(win);
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0, i, j, k, results_size = results.size(), 
        win, lose, w, l, match_arr[101][101] = {};
    vector<int> match_vec[101][2];

    for (i = 0; i < results_size; ++i) {
        win = results[i][0]; lose = results[i][1];

        for (j = 0; j < match_vec[win][1].size(); ++j) {
            w = match_vec[win][1][j];
            for (k = 0; k < match_vec[lose][0].size(); ++k) {
                l = match_vec[lose][0][k];
                if (match_arr[w][l]) continue;
                match(w, l, match_vec, match_arr);
            }
        }

        for (j = 0; j < match_vec[win][1].size(); ++j)
            match(match_vec[win][1][j], lose, match_vec, match_arr);
        for (j = 0; j < match_vec[lose][0].size(); ++j)
            match(win, match_vec[lose][0][j], match_vec, match_arr);

        match(win, lose, match_vec, match_arr);
    }

    for (i = 1; i <= n; ++i) {
        if (match_vec[i][0].size() + match_vec[i][1].size() == n - 1) ++answer;
    }

    return answer;
}