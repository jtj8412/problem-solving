//----------------------------------------------------------------------------------
// [ 신규 아이디 추천 ] https://programmers.co.kr/learn/courses/30/lessons/72410
//----------------------------------------------------------------------------------

#include <string>
using namespace std;

string solution(string id) {
    string answer;

    for (int i = 0; i < id.size(); ++i) {
        if (id[i] >= 'A' && id[i] <= 'Z') answer += id[i] + 32;
        else if ((id[i] >= 'a' && id[i] <= 'z') || 
            (id[i] >= '0' && id[i] <= '9') ||
            id[i] == '-' || id[i] == '_' ||
            (id[i] == '.' && answer.size() != 0 && answer.back() != '.')) 
            answer += id[i];
    }

    while (answer.back() == '.') answer.pop_back();

    if (answer.size() == 0) return "aaa";

    if (answer.size() > 15) answer = answer.substr(0, 15);
    if (answer.back() == '.') answer.pop_back();

    if (answer.size() == 1) answer.append(2, answer[0]);
    else if (answer.size() == 2) answer += answer[1];

    return answer;
}