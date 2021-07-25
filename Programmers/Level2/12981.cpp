/* 영어 끝말잇기 */

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0, 0};
    unordered_set<string> um;
    int size = words.size(), i;

    um.insert(words[0]);

    for (i = 1; i < size; ++i) {
        if (words[i - 1][words[i - 1].size() - 1] != words[i][0]) break;
        if (um.find(words[i]) != um.end()) break;
        um.insert(words[i]);
    }

    if (i != size) { answer[1] = (i / n) + 1; answer[0] = (i % n) + 1; }

    return answer;
}