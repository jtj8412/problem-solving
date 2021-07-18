#include <string>
#include <vector>
#include <typeinfo>
#include <iostream>
#include <string.h>

using namespace std;

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
    vector<string> s_tuple_vec = split(s, "},{");
    vector<vector<int>> tuple_vvec;

    s_tuple_vec[0].erase(0, 2);
    s_tuple_vec[s_tuple_vec.size() - 1].erase(s_tuple_vec.size() - 2, 2);

    for (int i = 0; i < s_tuple_vec.size(); ++i) {
        vector<string> s_tuple_vvec = split(s_tuple_vec[i], ",");
    }


    

    return answer;
}

int main() {
    vector<int> ans = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");

    // for (int i = 0; i < ans.size(); ++i) {
    //     cout << ans[i] << " ";
    // }
}