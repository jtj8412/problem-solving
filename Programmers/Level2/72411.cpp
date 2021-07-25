/* 메뉴 리뉴얼 */

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<int, int> um;

void combination(const string &order, int len, int idx = 0, int cnt = 0, int comb = 0) {
    if (len == cnt) {
        ++um[comb];
        return;
    }

    for (int i = idx; i <= order.size() - len + cnt; ++i)
        combination(order, len, i + 1, cnt + 1, comb + (1 << (order[i] - 'A')));
}

string bit_to_string(int n) {
    string ret;
    for (int bit = 1, i = 0; bit <= n; bit <<= 1, ++i) {
        if (bit & n) ret += 'A' + i;
    }
    return ret;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    unordered_map<int, int>::iterator iter, iterEnd = um.end();
    int o_size = orders.size(),
        c_size = course.size(), i, j, max;

    for (i = 0; i < c_size; ++i) {
        max = 0;
        for (j = 0; j < o_size; ++j) {
            if (orders[j].size() < course[i]) continue;
            combination(orders[j], course[i]);
        }
        for (iter = um.begin(); iter != iterEnd; ++iter) {
            if (iter->second > max) max = iter->second;
        }
        if (max < 2) continue;
        for (iter = um.begin(); iter != iterEnd; ++iter) {
            if (iter->second == max) answer.push_back(bit_to_string(iter->first));
        }
        um.clear();
    }

    sort(answer.begin(), answer.end());

    return answer;
}