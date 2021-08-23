//----------------------------------------------------------------------------------
// [ 4주차 ] https://programmers.co.kr/learn/courses/30/lessons/84325
//
// 개발자의 사용 언어에 따른 언어 선호도를 미리 해시맵에 저장하여 풀이
//----------------------------------------------------------------------------------

#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    unordered_map<string, int> dict;
    string answer, name, lang;
    int i, j, sum, val, max = 0;

    for (i = 0; i < languages.size(); ++i) dict[languages[i]] = preference[i];

    for (i = 0; i < table.size(); ++i) {
        name.clear();
        for (j = 0; table[i][j] != ' '; ++j) name += table[i][j];
        for (j = j + 1, sum = 0, val = 5; j <= table[i].size(); ++j) {
            if (table[i][j] == ' ' || table[i][j] == '\0') {
                sum += dict[lang] * val--;
                lang.clear();
            }
            else
                lang += table[i][j];
        }
        if (sum > max) {
            max = sum;
            answer = name;
        } else if (sum == max && answer > name)
            answer = name;
    }

    return answer;
}