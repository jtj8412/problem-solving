/* 위장 */

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> um;
    unordered_map<string, int>::iterator iter;

    for (int i = 0; i < clothes.size(); ++i) {
        string key = clothes[i][1];
        iter = um.find(key);
        if (iter == um.end()) {
            iter = um.insert(make_pair(key, 0)).first;
        }
        iter->second += 1;
    }

    for (pair<string, int> elem: um) {
        answer *= (elem.second + 1);
    }
    answer -= 1;

    return answer;
}