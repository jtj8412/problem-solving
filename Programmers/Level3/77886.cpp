//----------------------------------------------------------------------------------
// [ 110 옮기기 ] https://programmers.co.kr/learn/courses/30/lessons/77886
//
// 1. s[i]내의 모든 "110" 추출하고 그 외의 데이터는 answer[i]에 삽입
// 2. answer[i] 뒤에서 처음으로 나오는 '0' 뒤에다가 추출했던 모든 "110" 삽입
//----------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer(s.size());
    string tmp;
    int cnt, i, j, k, s_size, si_size, ansi_size, len;
    
    for (i = 0, s_size = s.size(); i < s_size; ++i) {
        if (s[i].size() <= 3) {
            answer[i] = s[i];
            continue;
        }
        si_size = s[i].size();
        cnt = 0;
        // answer[i]에 s[i]의 데이터를 넣으면서 "110"을 발견 시 추출
        for (int j = 0; j < si_size; ++j) {
            answer[i] += s[i][j];
            ansi_size = answer[i].size();
            if (ansi_size < 3) continue;
            while (answer[i][ansi_size - 3] == '1' && answer[i][ansi_size - 2] == '1' && answer[i][ansi_size - 1] == '0') {
                answer[i].erase(ansi_size - 3);
                ++cnt;
            }
        }

        // answer[i]를 뒤에서부터 '0' 탐색
        ansi_size = answer[i].size();
        for (j = ansi_size - 1; j >= 0 && answer[i][j] == '1'; --j);
        
        // 위에서 탐색한 '0'의 뒷 지점부터 끝 지점 까지의 데이터를 뒤로 미룸
        answer[i].resize(s[i].size());
        for (k = j + 1; k < ansi_size; ++k) 
            answer[i][si_size - (ansi_size - j) + (k - j)] = answer[i][k];

        // 위에서 탐색한 '0' 뒤에 추출했던 "110" 을 모두 삽입
        len = cnt * 3;
        for (k = 1; k <= len; k += 3) {
            answer[i][j + k] = answer[i][j + k + 1] = '1';
            answer[i][j + k + 2] = '0';
        }
    }

    return answer;
}

int main() {
    vector<string> ans = solution({"110"});
    cout << ans.size() << endl;
    for (auto s : ans) {
        cout << s << "\t" << s.size()<< endl;
    }
}