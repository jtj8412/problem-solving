#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, unordered_set<string>> ban_me;
    unordered_map<string, int> ban_num;
    unordered_map<string, int> mail;

    for (int i = 0; i < id_list.size(); ++i) {
        ban_num[id_list[i]]; 
        ban_me[id_list[i]];
        mail[id_list[i]];
    }

    for (int i = 0; i < report.size(); ++i) {
        int idx = report[i].find(' ');
        string report_user = report[i].substr(0, idx);
        string reported_user = report[i].substr(idx + 1);

        if (ban_me[reported_user].find(report_user) != ban_me[reported_user].end()) continue;

        ban_me[reported_user].insert(report_user);

        if (++ban_num[reported_user] == k) {
            for (auto user : ban_me[reported_user]) mail[user]++;
        } else if (ban_num[reported_user] > k) {
            mail[report_user]++;
        }
    }

    for (int i = 0; i < id_list.size(); ++i) {
        answer.push_back(mail[id_list[i]]);
    }

    return answer;
}