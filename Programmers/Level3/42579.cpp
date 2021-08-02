/* 베스트앨범 */

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct DATA {
    vector<pair<int, int>> vec;
    int sum = 0;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, DATA> dict;
    vector<DATA> tmp;

    for (int i = 0; i < genres.size(); ++i) {
        dict[genres[i]].sum += plays[i];
        dict[genres[i]].vec.push_back(make_pair(i, plays[i]));
        sort(dict[genres[i]].vec.begin(), dict[genres[i]].vec.end(), [](const pair<int,int> &a, const pair<int,int> &b)->bool{return a.second > b.second; });
        if (dict[genres[i]].vec.size() == 3) dict[genres[i]].vec.pop_back();
    }
    for (auto kv : dict) tmp.push_back(kv.second);
    sort(tmp.begin(), tmp.end(), [](const DATA &a, const DATA &b)->bool{return a.sum > b.sum;});
    for (auto data : tmp) {
        for (auto kv : data.vec) answer.push_back(kv.first);
    }

    return answer;
}