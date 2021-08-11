//----------------------------------------------------------------------------------
// [ 로또의 최고 순위와 최저 순위 ] https://programmers.co.kr/learn/courses/30/lessons/77484
//
// 1. 로또에 적은 숫자를 배열(correct)에 저장
// 2. correct 배열에 정답 숫자(win_nums)의 요소들을 인덱스로 최소 정답 갯수 획득
// 3. 최소 정답 갯수에 로또의 0의 갯수를 합한 것이 최대 정답 갯수
// 4. 최소/최대 정답 갯수를 통한 정답 도출
//----------------------------------------------------------------------------------

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
