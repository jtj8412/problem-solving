//----------------------------------------------------------------------------------
// [ 10주차_교점에 별 만들기 ] https://programmers.co.kr/learn/courses/30/lessons/87377
//
// ax + by + e = 0, cx + dy + f = 0 직선의 교점을 구하는 식
// n = (ad - bc)    (n == 0 일 경우 평행)
// x = (bf - ed) / n
// y = (ec - af) / n
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<vector<int>> lines) {
    vector<string> answer;
    vector<pair<long long, long long>> vec;
    long long t, r, l, b, n, x, y, xx, yy;
    t = r = numeric_limits<long long>::min(); l = b = numeric_limits<long long>::max();
    
    for (int i = 0; i < lines.size() - 1; ++i) {
        for (int j = i + 1; j < lines.size(); ++j) {
            if ((n = (long long)lines[i][0] * lines[j][1] - (long long)lines[i][1] * lines[j][0]) == 0) continue; // 평행

            xx = (long long)lines[i][1] * lines[j][2] - (long long)lines[i][2] * lines[j][1];
            yy = (long long)lines[i][2] * lines[j][0] - (long long)lines[i][0] * lines[j][2];

            if (xx % n != 0 || yy % n != 0) continue; // 소수 좌표
            
            x = xx / n;
            y = yy / n;

            vec.push_back(make_pair(x, y));

            b = min(b, y); t = max(t, y);
            l = min(l, x); r = max(r, x);
        }    
    }

    answer.resize(t - b + 1);
    for (int i = 0; i < answer.size(); ++i) {
        answer[i].assign(r - l + 1, '.');
    }

    for (auto pos : vec) {
        answer[t - pos.second][pos.first - l] = '*';
    }

    return answer;
}