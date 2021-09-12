#include <string>
#include <vector>
#include <unordered_map>
#include <math.h>
#include <algorithm>
using namespace std;

#define IN 0
#define OUT 1

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<string, int> dict;
    unordered_map<string, int> ans_dict;
    unordered_map<string, int> time_dict;
    vector<string> car_name;
    int last_time = 1439;

    for (int i = 0; i < records.size(); ++i) {
        int time = stoi(records[i].substr(0,2)) * 60 + stoi(records[i].substr(3,2));
        string name = records[i].substr(6, 4);
        int cmd = (records[i][11] == 'I') ? IN : OUT;

        if (dict.find(name) == dict.end()) {
            dict[name] = time;
        } else {
            time_dict[name] += time - dict[name];
            dict.erase(name);
        }
    }

    for (auto kv : dict) {
        time_dict[kv.first] += last_time - kv.second;
    }

    for (auto kv : time_dict) {
        ans_dict[kv.first] = fees[1];
        if (kv.second > fees[0]) ans_dict[kv.first] += (ceil)((double)(kv.second - fees[0]) / fees[2]) * fees[3];
        car_name.push_back(kv.first);
    }

    sort(car_name.begin(), car_name.end());

    for (auto s : car_name) {
        answer.push_back(ans_dict[s]);
    }

    return answer;
}