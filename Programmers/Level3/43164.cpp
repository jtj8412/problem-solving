/* 여행경로 */

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, vector<pair<string, bool>>> dict;
vector<string> answer;
int N;

bool logic(const string &key, int cnt = 0) {
    if (cnt == N) return true;
    for (int i = 0; i < dict[key].size(); ++i) {
        if (dict[key][i].second) continue;
        answer.push_back(dict[key][i].first);
        dict[key][i].second = true;
        if (logic(dict[key][i].first, cnt + 1)) return true;
        answer.pop_back();
        dict[key][i].second = false;
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    N = tickets.size();
    for (auto ticket : tickets) dict[ticket[0]].push_back(make_pair(ticket[1], false));
    for (auto kv : dict) sort(dict[kv.first].begin(), dict[kv.first].end());
    answer.push_back("ICN");
    logic("ICN");
    return answer;
}