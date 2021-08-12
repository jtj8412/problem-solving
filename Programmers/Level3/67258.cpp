//----------------------------------------------------------------------------------
// [ 보석 쇼핑 ] https://programmers.co.kr/learn/courses/30/lessons/67258
// 
// 1. 해시맵(dict)에 모든 보석의 종류(max) 저장
// 2. right(r) 인덱스를 통해 배열(gems)을 탐색하면서 해시맵에 보석 소지수(dict) 추가
// 3. 2에서의 보석 소지수(dict)를 추가한 보석이 새로 추가한 보석일 경우 보석 종류(cnt)에 +1
// 4. 보석 종류를 모두 모았을 경우(cnt==max) right(r) 인덱스를 기준으로 조건 충족 최소치를
//    만족하는 left(l) 인덱스를 탐색
// 5. right와 left 사이 구간이 최소일 경우 정답
//----------------------------------------------------------------------------------

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer = {0, 100000};
    unordered_map<string, int> dict;
    int max = 0, l = 0, r = 0, size = gems.size(), cnt = 0;

    for (auto s : gems) dict[s];
    max = dict.size();

    for (r = 0; r < size; ++r) {
        if (++dict[gems[r]] == 1 && ++cnt == max) {
            while (--dict[gems[l++]] != 0);
            --cnt;
            if (r - l + 1 < answer[1] - answer[0]) {
                answer[0] = l; answer[1] = r + 1;
            }
        }
    }

    return answer;
}