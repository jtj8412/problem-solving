/* 후보키 */

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int solution(vector<vector<string>> relation) {
    const int COLUMN_MAX = 8, column_size = relation[0].size(), row_size = relation.size(), col_bit_max = 1 << column_size;
    int bit, cur_bit, same_bit, i, j;
    unordered_map<string, int> um[COLUMN_MAX];
    vector<int> col_vec, answer_vec;
    queue<int> q;

    for (i = 0; i < column_size; ++i) {
        for (j = 0; j < row_size; ++j)
            um[i][relation[j][i]] |= (1 << j);
    }
    for (bit = 1; bit != col_bit_max; bit <<= 1) q.push(bit);
    
    while (!q.empty()) {
        cur_bit = q.front(); q.pop();
        for (i = 0; i < answer_vec.size(); ++i) {
            if ((answer_vec[i] & cur_bit) == answer_vec[i]) break; 
        }
        if (i != answer_vec.size()) continue;
        for (i = 0, bit = 1; bit != col_bit_max; ++i, bit <<= 1) {
            if (cur_bit & bit) col_vec.push_back(i);
        }
        for (i = 0; i < row_size; ++i) {
            same_bit = 0xfffff;
            for (j = 0; j < col_vec.size(); ++j) same_bit &= um[col_vec[j]][relation[i][col_vec[j]]];
            if (same_bit != (1 << i)) break;
        }
        if (i == row_size) {
            answer_vec.push_back(cur_bit);
        } else {
            for (bit = col_bit_max >> 1; !(bit & cur_bit); bit >>= 1) q.push(cur_bit | bit);
        }
        col_vec.clear();
    }
    return answer_vec.size();
}