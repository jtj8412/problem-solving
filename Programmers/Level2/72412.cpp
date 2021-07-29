/* 순위 검색 */

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> arr[1 << 8];
unordered_map<string, int> dict = {
    {"-", 0}, {"cpp", 1}, {"java", 2}, {"python", 3},
    {"backend", 1 << 2}, {"frontend", 2 << 2},
    {"junior", 1 << 4}, {"senior", 2 << 4},
    {"chicken", 1 << 6}, {"pizza", 2 << 6}
};

int count(int index, int cond) {
    int ret = 0;
    for (auto val : arr[index]) {
        if (val >= cond) ++ret;
    }
    return ret;
}

int execute(int query, int cond, int flag = 0b11, int index = 0) {
    int sum = 0, start, end, i, unit = flag & (flag >> 1);
    if (flag == 0b1100000000) return count(index, cond);
    if (!(query & flag)) { start = unit; end = flag;}
    else { start = end = query & flag; }
    for (i = start; i <= end; i += unit) sum += execute(query, cond, flag << 2, index | i);
    return sum;
}

vector<string> split(string s, string delim) {
    vector<string> ret;
    int i = 0, j;
    while ((j = s.find(delim, i)) != string::npos) {
        ret.push_back(s.substr(i, j - i));
        i = j + delim.size();
    }
    ret.push_back(s.substr(i, s.size() - i));
    return ret;
}

vector<int> solution(vector<string> info_vec, vector<string> query_vec) {
    vector<int> answer;
    int flag, val, i;
    
    for (auto info : info_vec) {
        flag = 0, val;
        vector<string> v = split(info, " ");
        val = stoi(v.back()); v.pop_back();
        for (auto s : v) flag |= dict[s];
        arr[flag].push_back(val);
    }

    for (auto query : query_vec) {
        flag = 0;
        i = query.rfind(' ');
        val = stoi(query.substr(i + 1, query.size() - i - 1));
        query.erase(i, query.size() - i);
        vector<string> v = split(query, " and ");
        for (auto s : v) flag |= dict[s];
        answer.push_back(execute(flag, val));
    }
    return answer;
}