/* 로또의 최고 순위와 최저 순위 */

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int correct[46] = {}, correct_cnt = 0;

    for (int i = 0; i < lottos.size(); ++i) 
        correct[lottos[i]]++;

    for (int i = 0; i < win_nums.size(); ++i) {
        if (correct[win_nums[i]] != 0) correct_cnt++;
    }

    answer.push_back(7 - (correct_cnt + correct[0]));
    answer.push_back(7 - correct_cnt);

    for (int i = 0; i < 2; ++i) {
        if (answer[i] == 7) answer[i] = 6;
    }

    return answer;
}
