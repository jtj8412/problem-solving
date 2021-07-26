/* 후보키 */

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

const int ROW_MAX = 8, ROW_BIT_MAX = 1 << ROW_MAX;
unordered_map<string, int> um[ROW_MAX];
int flag[ROW_BIT_MAX] = {};
queue<int> q;
int column_size, row_size, bit_max;
vector<int> answer_vec;

int last_bit_idx(int n) {
    int bit = bit_max, i = column_size;
    for (; !(bit & n) && bit; bit >>= 1, --i);
    return i;
}

int solution(vector<vector<string>> relation) {
    int answer = 0, bit, i, j;
    /* init */
    row_size = relation.size();
    column_size = relation[0].size();
    bit_max = 1 << column_size;
    fill_n(flag, bit_max, 0xff);
    for (i = 0; i < column_size; ++i) {
        for (j = 0; j < row_size; ++j)
            um[i][relation[j][i]] += (1 << j);
    }
    for (bit = 1; bit != bit_max; bit <<= 1) q.push(bit);
    
    /* logic */
    while (!q.empty()) {
        int cur_bit = q.front(), new_idx = last_bit_idx(cur_bit), new_bit = (1 << new_idx), old_bit = cur_bit ^ new_bit, same_bit, res_bit = 0;
        q.pop();
        for (i = 0, bit = 1; bit != bit_max; ++i, bit <<= 1) {
            if ((flag[old_bit] & bit) && (same_bit = flag[old_bit] & um[new_idx][relation[i][new_idx]]) != bit) res_bit |= same_bit;
        }
        flag[cur_bit] = res_bit;
        if (!res_bit) {
            ++answer;
            answer_vec.push_back(cur_bit);
        } else {
            for (bit = (new_bit << 1); bit != bit_max; bit <<= 1) { 
                for (i = 0; i < answer_vec.size(); ++i) {
                    if (answer_vec[i] & (cur_bit | bit) == answer_vec[i]) break;
                }
                if (i == answer_vec.size()) q.push(cur_bit | bit);
            }
        }
    }

    return answer;
}

int main() {
    vector<vector<string>> vvec = {{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}};
    cout << solution(vvec) << endl;
}
