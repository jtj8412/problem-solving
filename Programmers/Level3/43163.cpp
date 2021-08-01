/* 단어 변환 */

#include <string>
#include <vector>
#include <algorithm>
#define INT_MAX 2147483647
using namespace std;

int dfs[50][50] = {}, words_size, target_idx, ans = INT_MAX;

void logic(int idx, int visited, int cnt = 0) {
    if (idx == target_idx) { ans = min(ans, cnt); return; }
    for (int i = 0; i < words_size; ++i) {
        if (!dfs[idx][i] || (1 << i) & visited) continue;
        logic(i, visited | (1 << i), cnt + 1);
    }
}

int solution(string begin, string target, vector<string> words) {
    int i, j, k, cnt, word_size;

    words.push_back(begin);
    words_size = words.size(), word_size = words[0].size();

    if ((target_idx = find(words.begin(), words.end(), target) - words.begin()) == words_size) return 0;

    for (i = 0; i < words_size - 1; ++i) {
        for (j = i + 1; j < words_size; ++j) {
            cnt = 0;
            for (k = 0; k < word_size && cnt != 2; ++k) {
                if (words[i][k] != words[j][k]) ++cnt;
            }
            if (cnt == 1) dfs[i][j] = dfs[j][i] = 1;
        }
    }
    
    logic(words_size - 1, 1 << (words_size - 1));
    return (ans == INT_MAX) ? 0 : ans;
}