//----------------------------------------------------------------------------------
// [ 불량 사용자 ] https://programmers.co.kr/learn/courses/30/lessons/64064
//
// 1. 각 불량 사용자 아이디(banned_id)로 만들 수 있는 아이디를 banned_vec에 저장한다
//    단, 편의를 의해 bit flag 상태로 만든다
// 2. 1개부터 시작해서 차례대로 n개의 불량 사용자 아이디로 만들 수 있는 경우를 ans_vec[i]에 저장한다
//   2-1. 중복된 아이디를 선택하지 않도록 한다
//   2-2. 사용된 조합은 cache에 저장하고, 두번 저장하지 않게 한다
// 3. 모든 불량 아이디 사용자를 이용해 만들 수 있는 경우의 수, ans_vec[size-1]가 정답이다
//----------------------------------------------------------------------------------

#include <string>
#include <vector>
using namespace std;

int solution(vector<string> user_id, vector<string> banned_id) {
    int cache[1<<9] = {}, i, j, k, flag;
    vector<int> banned_vec[8], ans_vec[8];

    for (i = 0; i < banned_id.size(); ++i) {
        for (j = 0; j < user_id.size(); ++j) {
            if (user_id[j].size() != banned_id[i].size()) continue;
            for (k = 0; k < user_id[j].size(); ++k) {
                if (user_id[j][k] != banned_id[i][k] && banned_id[i][k] != '*') break;
            }
            if (k == user_id[j].size()) banned_vec[i].push_back(j);
        }
    }

    for (i = 0; i < banned_vec[0].size(); ++i) 
        ans_vec[0].push_back(1 << banned_vec[0][i]);

    for (i = 1; i < banned_id.size(); ++i) {
        for (j = 0; j < ans_vec[i-1].size(); ++j) {
            for (k = 0; k < banned_vec[i].size(); ++k) {
                if (ans_vec[i-1][j] & (1 << banned_vec[i][k])) continue;
                flag = ans_vec[i-1][j] | (1 << banned_vec[i][k]);
                if (cache[flag]) continue;
                cache[flag] = 1;
                ans_vec[i].push_back(flag);
            }
        }
    }

    return ans_vec[banned_id.size()-1].size();
}