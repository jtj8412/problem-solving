/* 튜플 */

#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX_NUMBER 100000

bool compare(const vector<int> &a, const vector<int> &b) {
    return a.size() < b.size();
}

vector<string> split(string s, const char* delim) {
    int prev_idx = 0,
        delim_size = strlen(delim),
        idx = 0;
    vector<string> ret;

    while ((idx = s.find(delim, idx + 1)) != string::npos) {
        ret.push_back(s.substr(prev_idx, idx - prev_idx));
        prev_idx = idx + delim_size;
    }
    ret.push_back(s.substr(prev_idx, s.length() - prev_idx));

    return ret;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> tuple_vec = split(s, "},{");
    vector<vector<int>> tuple_vvec;
    int mem[MAX_NUMBER + 1] = {};

    tuple_vec[0].erase(0, 2);
    tuple_vec[tuple_vec.size() - 1].erase(tuple_vec[tuple_vec.size() - 1].size() - 2, 2);

    for (int i = 0; i < tuple_vec.size(); ++i) {
        vector<string> tmp_vvec = split(tuple_vec[i], ",");
        vector<int> new_vec;
        for (int j = 0; j < tmp_vvec.size(); ++j) {
            new_vec.push_back(stoi(tmp_vvec[j]));
        }
        tuple_vvec.push_back(new_vec);
    }

    sort(tuple_vvec.begin(), tuple_vvec.end(), compare);

    for (int i = 0; i < tuple_vvec.size(); ++i) {
        for (int j = 0; j < tuple_vvec[i].size(); ++j) {
            if (!mem[tuple_vvec[i][j]]) {
                mem[tuple_vvec[i][j]] = 1;
                answer.push_back(tuple_vvec[i][j]);
                break;
            }
        }
    }

    return answer;
}

int main() {
    vector<int> ans = solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}