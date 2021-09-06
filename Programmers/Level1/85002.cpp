//----------------------------------------------------------------------------------
// [ 위클리 챌린지 6주차 ] https://programmers.co.kr/learn/courses/30/lessons/85002
//----------------------------------------------------------------------------------

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct DATA {
    float rate = 0;
    int heavy = 0, weight, win = 0, lose = 0, idx;
};

vector<int> solution(vector<int> weights, vector<string> head2head) {
    int i, j, n = weights.size();
    vector<int> answer(n);
    vector<DATA> data_vec(n);

    for (i = 0; i < n; ++i) {
        data_vec[i].idx = i;
        data_vec[i].weight = weights[i];
        for (j = 0; j < n; ++j) {
            if (head2head[i][j] == 'N') continue;
            if (head2head[i][j] == 'W') {
                ++data_vec[i].win;
                if (weights[j] > weights[i]) ++data_vec[i].heavy;
            } else ++data_vec[i].lose;
        }
        data_vec[i].rate = (data_vec[i].win + data_vec[i].lose == 0) ? 0: data_vec[i].win / (float)(data_vec[i].win + data_vec[i].lose);
    }

    sort(data_vec.begin(), data_vec.end(), [](const DATA &a, const DATA &b)->bool{
        if (a.rate != b.rate) return a.rate > b.rate;
        if (a.heavy != b.heavy) return a.heavy > b.heavy;
        if (a.weight != b.weight) return a.weight > b.weight;
        return a.idx < b.idx;
    });

    for (i = 0; i < n; ++i) answer[i] = data_vec[i].idx;

    return answer;
}