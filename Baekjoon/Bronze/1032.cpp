//----------------------------------------------------------------------------------
// [ 명령 프롬프트 ] https://www.acmicpc.net/problem/1032
//----------------------------------------------------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<string> s_vec;
    string answer;

    cin >> n; cin.ignore();
    s_vec.resize(n);
    for (int i = 0; i < n; ++i) cin >> s_vec[i];

    for (int i = 0, j; i < s_vec[0].size(); ++i) {
        char c = s_vec[0][i];
        for (j = 1; j < n; ++j) {
            if (s_vec[j][i] != c) break;
        }
        if (j == n) answer += c;
        else answer += '?';
    }

    cout << answer;
}