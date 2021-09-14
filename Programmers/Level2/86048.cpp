//----------------------------------------------------------------------------------
// [ 위클리 챌린지 7주차 ] https://programmers.co.kr/learn/courses/30/lessons/86048
//----------------------------------------------------------------------------------

#include <vector>
using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
    int i = 0, j = 0, cnt = 0, n = enter.size();
    vector<int> answer(n);
    vector<pair<int,int>> vec(n + 1);
    
    for (i = 0; i < n; ++i) {
        vec[enter[i]] = {i + 1, cnt++};
        while (j != n && vec[leave[j]].first) {
            vec[leave[j]].second += (i + 1) - vec[leave[j]].first;
            ++j; --cnt;
        }
    }

    for (i = 0; i < n; ++i) answer[i] = vec[i+1].second;

    return answer;
}