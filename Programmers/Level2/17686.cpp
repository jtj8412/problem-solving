/* [3차] 파일명 정렬 */

#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

struct DATA {
    string head;
    int num, idx;
    DATA(const string &s, int idx) : idx(idx) { 
        int i = -1, j;
        while (!isdigit(s[++i]));
        for (j = i; isdigit(s[j]); ++j);
        this->head = s.substr(0, i);
        this->num = stoi(s.substr(i, j - i));
        transform(this->head.begin(), this->head.end(), this->head.begin(), ::tolower);
    }
};

bool compare(const DATA& a, const DATA& b) {
    int comp = a.head.compare(b.head);
    if (comp) return (comp < 0);
    return (a.num == b.num) ? false : a.num < b.num;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<DATA> vec;

    for (int i = 0; i < files.size(); ++i) vec.push_back(DATA(files[i], i));
    stable_sort(vec.begin(), vec.end(), compare);
    for (int i = 0; i < vec.size(); ++i) answer.push_back(files[vec[i].idx]);

    return answer;
}