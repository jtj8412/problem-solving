//----------------------------------------------------------------------------------
// [ 피로도 ] https://programmers.co.kr/learn/courses/30/lessons/87946
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int answer = 0, n;
vector<vector<int>>* pVec;

void logic(int visited, int k, int val) {
    answer = max(answer, val);

    for (int i = 0, bit = 1; i < n; ++i, bit <<= 1) {
        if ((visited & bit) || (*pVec)[i][0] > k) continue;
        logic(visited | bit, k - (*pVec)[i][1], val + 1);
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    n = dungeons.size();
    pVec = &dungeons;

    logic(0, k, 0);

    return answer;
}