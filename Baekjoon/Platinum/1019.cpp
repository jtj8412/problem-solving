//----------------------------------------------------------------------------------
// [ 책 페이지 ] https://www.acmicpc.net/problem/1019
//
// 1. ~9, ~99, ~999 까지일 때 각 숫자가 나타나는 횟수는 1, 20, 300 으로 (숫자 0 제외)
//    (이전 단계) x 10 + (자릿 수(1, 10, 100...)) 라는 규칙이 있다.
// 2. 30000 ~ 39999 일 때 맨 앞자리에 의해 3이 나타나는 횟수는 자릿 수(10000) 만큼이다.
//    30000 ~ 34952 일 경우는 0부터 4952까지인 (4952 + 1)번 만큼이다.
// 3. 1,2를 이용하여 풀이한다.
//----------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int ans[10] = {};

void add_ans(int len, int val) {
    for (int i = 0; i < len; ++i) ans[i] += val;
}

int main() {
    vector<int> cnt_vec = {1};
    int level = 1, i, j;
    string s;

    cin >> s;

    for (i = 1; i < s.size() - 1; ++i) {
        level *= 10;
        cnt_vec.push_back(cnt_vec[i - 1] * 10 + level);
    }
    level *= 10;

    for (i = 0; i < s.size() - 1; ++i) {
        add_ans(10, cnt_vec[cnt_vec.size() - i - 1] * (s[i] - '0'));
        add_ans(s[i] - '0', level);
        if (i != s.size() - 1) ans[s[i] - '0'] += stoi(s.substr(i + 1)) + 1;
        level /= 10;
    }
    add_ans(s.back() + 1 - '0', 1);

    level = pow(10, s.size() - 1);
    while (level != 0) {
        ans[0] -= level;
        level /= 10;
    }

    for (auto i : ans) {
        cout << i << " ";
    }
}
