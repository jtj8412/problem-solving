#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>
#include <stack>
#include <map>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;

    int cur_extend = 0;
    queue<pair<int, int>> extends; // end_time, count

    for (int t = 0; t < 24; ++t)
    {
        if (!extends.empty() && extends.front().first == t)
        {
            cur_extend -= extends.front().second;
            extends.pop();
        }

        int cur_player = players[t];
        int need_extend = cur_player / m;

        if (need_extend > cur_extend)
        {
            int extend = need_extend - cur_extend;
            extends.push(make_pair(t + k, extend));
            cur_extend += extend;
            answer += extend;
        }
    }

    return answer;
}