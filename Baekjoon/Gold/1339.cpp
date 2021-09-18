//----------------------------------------------------------------------------------
// [ 단어 수학 ] https://www.acmicpc.net/problem/1339
//----------------------------------------------------------------------------------

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n, i, j, answer = 0, cnt[26] = {}, arr[26] = {};
    string str[10];

    // init
    cin >> n; cin.ignore();
    for (i = 0; i < n; ++i) cin >> str[i];

    // logic
    for (i = 0; i < n; ++i) {
        int val = 1;
        for (j = str[i].size() - 1; j >= 0; --j) {
            cnt[str[i][j] - 'A'] += val;
            val *= 10;
        }
    }

    for (i = 9; i >= 0; --i) {
        int *p = max_element(cnt, cnt + 26);
        arr[p - cnt] = i;
        *p = -1;
    }

    for (i = 0; i < n; ++i) {
        int val = 0;
        for (j = 0; j < str[i].size(); ++j) {
            val *= 10;
            val += arr[str[i][j] - 'A'];
        }
        answer += val;
    }

    cout << answer;
}
