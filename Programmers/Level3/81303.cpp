//----------------------------------------------------------------------------------
// [ 표 편집 ] https://programmers.co.kr/learn/courses/30/lessons/81303
//
// 표를 10, 100 ... 등분했을 때 그 구간에 남아있는 행의 개수를 담는 배열을 만듭니다.
// 각 구간에 남아있는 데이터 개수는 N 번째 데이터의 인덱스를 찾는데 길잡이가 됩니다.
// 시간복잡도 O(N) (단, N의 최댓값인 1,000,000 기준으로 최악의 경우 60배 가량의 상수배가 발생합니다.)
// 공간복잡도 O(N)
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

string answer;
vector<int> vec[5];
int section_max;

int GetIndex(int order) {
    int idx = 0, cnt = 0;

    for (int i = 0, val = section_max, prev = 0; val != 1; ++i, val /= 10, prev *= 10) {
        for (int j = prev; cnt + vec[i][j] < order; ++j) {
            cnt += vec[i][j];
            idx += val;
            prev++;
        }
    }

    while (cnt != order) {
        if (answer[idx] == 'O') cnt++;
        idx++;
    }

    return idx - 1;
}

string solution(int n, int k, vector<string> cmds) {
    stack<int> stk;
    int idx = k, order = k + 1, tmp;

    answer.resize(n, 'O');
    tmp = log10(n);
    section_max = (tmp == log10(n)) ? pow(10, tmp - 1) : pow(10, tmp);

    for (int i = 0, size = 10, val = section_max; val != 1; ++i, size *= 10, val /= 10) {
        vec[i].resize(size + 1, val);
        vec[i][n / val] = n % val;
    }

    for (int i = 0; i < cmds.size(); ++i) {
        switch (cmds[i][0]) {
        case 'Z':
            tmp = stk.top(); stk.pop();
            answer[tmp] = 'O'; 
            if (tmp < idx) order++;
            for (int j = 0, val = section_max; val != 1; ++j, val /= 10) vec[j][tmp / val]++;
            break;

        case 'C':
            stk.push(idx);
            answer[idx] = 'X';
            for (int j = 0, val = section_max; val != 1; ++j, val /= 10) vec[j][idx / val]--;
            if (order > (n - stk.size())) --order;
            idx = GetIndex(order);
            break;

        case 'U':
            order -= stoi(cmds[i].substr(2));
            idx = GetIndex(order);
            break;

        case 'D':
            order += stoi(cmds[i].substr(2));
            idx = GetIndex(order);
            break;
        }
    }

    return answer;
}