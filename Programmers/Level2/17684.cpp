/* [3차] 압축 */

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dict;
    string tmp;
    int cnt = 26, i;

    tmp = "A";
    for (i = 1; i <= 26; ++i) { dict[tmp] = i; ++tmp[0]; }

    tmp.clear();
    for (auto word : msg) {
        if (dict[tmp + word]) { tmp += word; continue; }
        answer.push_back(dict[tmp]);
        dict[tmp + word] = ++cnt;
        tmp = word;
    }
    answer.push_back(dict[tmp]);

    return answer;
}