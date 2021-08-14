//----------------------------------------------------------------------------------
// [ 브라이언의 고민 ] https://programmers.co.kr/learn/courses/30/lessons/1830
//
// 1. 문장에서 먼저 등장한 순서대로 각 소문자의 위치 리스트를 vector에 저장한다 (vvec)
// 2. 소문자의 위치 리스트(vvec)를 토대로 각 소문자의 범위를 리스트(vec)에 저장한다
//    pair<int,int>에서 first는 좌측, second는 우측이다
//    그리고 유효성을 검사한다.
//  2-1. vvec[i]에 저장된 소문자 갯수가 2일 경우 aAa, aAAAa, aAxAxAa ... 이다
//       조건으로 두 소문자의 간격이 두 칸 이상이여야 한다
//       범위는 <가장 앞 소문자 위치 ~ 가장 뒷 소문자 위치>
//  2-2. vvec[i]에 저장된 소문자 갯수가 1 또는 3이상일 경우 AaA, AaAaA, AaAaAaA ... 이다
//       조건으로 각 소문자의 간격이 2 여야한다
//       범위는 <가장 앞 소문자의 위치 - 1 ~ 가장 뒷 소문자의 위치 + 1>
//  2-3. 만약 이전에 나온 소문자 범위안에 포함되어있을 경우, 두 종류의 소문자가 두 번
//       적용되기위한 여러 조건들을 체크한다
//       이 경우 새로운 소문자 범위가 생기는 것이 아니므로 범위 리스트(vec)에 추가하지 않는다
//  2-4. 2-3 조건에도 부적합하고, 이전 범위보다 우측에 위치한 것이 아니라면 실패로 간주한다
// 3. 소문자 범위 리스트(vec)을 토대로 문자를 생성한다
//    각 소문자 범위(vec[i]) 외의 범위는 그대로 문자를 생성한다
//----------------------------------------------------------------------------------

#include <string>
#include <vector>
using namespace std;

string solution(string sentence) {
    string answer, invalid = "invalid";
    vector<vector<int>> vvec;
    vector<pair<int, int>> vec = {{-1,-1}};
    int index[26] = {}, i, j;
    
    fill(index, index+26, -1);

    for (i = 0; i < sentence.size(); ++i) { // 소문자 위치 리스트(vvec) 초기화
        if (sentence[i] == ' ') return invalid;
        if (!(sentence[i] >= 'a' && sentence[i] <= 'z')) continue;
        if (index[sentence[i]-'a'] == -1) {
            index[sentence[i]-'a'] = vvec.size();
            vvec.push_back(vector<int>({i}));
        } else {
            vvec[index[sentence[i]-'a']].push_back(i);
        }
    }

    for (i = 0; i < vvec.size(); ++i) { // 소문자 범위 리스트(vec) 초기화 및 유효성 검사
        pair<int, int> data;
        pair<int, int> prev = vec.back();

        if (vvec[i].size() == 2) {
            data = make_pair(vvec[i].front(), vvec[i].back());
            if (data.second - data.first < 2) return invalid;
        }
        else {
            data = make_pair(vvec[i].front() - 1, vvec[i].back() + 1);
            for (j = 1; j < vvec[i].size(); ++j) {
                if (vvec[i][j] - vvec[i][j-1] != 2) return invalid;
            }
        }
        if (data.first > prev.first && data.second < prev.second) {
            if (!(vvec[i].size() == (prev.second - prev.first) / 2 - 1 && ((prev.second - prev.first - 1) & 1) &&
                vvec[i].front() - 2 == prev.first && vvec[i].back() + 2 == prev.second)) return invalid;
        } else if (data.first > prev.second) vec.push_back(data);
        else return invalid;
    }
    if (vec.size() > 1 && (vec[1].first < 0 || vec.back().second >= sentence.size())) return invalid;
 
    vec.push_back(make_pair(sentence.size(), -1));
    for (i = 1; i < vec.size(); ++i) { // 정답 출력
        for (j = vec[i-1].second + 1; j < vec[i].first; ++j) answer += sentence[j];
        if (vec[i].first - vec[i-1].second - 1 > 0) answer += ' ';
        for (j = vec[i].first; j <= vec[i].second; ++j) {
            if (sentence[j] >= 'A' && sentence[j] <= 'Z') answer += sentence[j];
        }
        answer += ' ';
    }
    while (answer.back() == ' ') answer.pop_back();

    return answer;
}