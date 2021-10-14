//----------------------------------------------------------------------------------
// [ n^2 배열 자르기 ] https://programmers.co.kr/learn/courses/30/lessons/87390
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int val;
    for (int i = (left / n); i <= (right / n); ++i) for (int j = 0; j < n; ++j) {
        if ((val = i * n + j) < left || val > right) continue;
        answer.push_back(max(i, j) + 1);
    }
    return answer;
}