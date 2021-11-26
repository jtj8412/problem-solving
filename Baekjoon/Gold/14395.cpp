//----------------------------------------------------------------------------------
// [ 4 연산 ] https://www.acmicpc.net/problem/14395
//
// '-' 연산은 0이 되버리기 때문에 무의미한 연산
// '/' 연산은 1이 되버리기 때문에 첫 연산에만 사용 가능한 연산
// BFS로 탐색하면서 중복된 탐색 여부는 map으로 확인한다
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

struct DATA { long long val; string exp; };

string logic() {
    string answer;
    queue<DATA> q;
    map<long long, string> m;
    long long s, t;
    cin >> s >> t;
    if (s == t) return "0";
    if (t == 1) return "/";
    q.push(DATA({s, ""})); m.insert(make_pair(s, ""));
    if (s != 1) {q.push(DATA({1, "/"})); m.insert(make_pair(1, "/"));}
    while (!q.empty()) {
        DATA& cur = q.front();
        if (!answer.empty() && cur.exp.size() == answer.size()) break;
        long long next1 = cur.val + cur.val, next2 = cur.val * cur.val;
        if (next1 < t) {
            auto it = m.find(next1);
            if (it == m.end() || cur.exp.size() + 1 < it->second.size() || (cur.exp.size() + 1 == it->second.size() && cur.exp + "+" < it->second)) {
                q.push(DATA({next1, cur.exp + "+"}));
                m.insert(make_pair(next1, cur.exp + "+"));
            }
        } else if (next1 == t && (answer.empty() || cur.exp + "+" < answer)) {
            answer = cur.exp + "+";
        }
        if (next2 < t) {
            auto it = m.find(next2);
            if (it == m.end() || cur.exp.size() + 1 < it->second.size() || (cur.exp.size() + 1 == it->second.size() && cur.exp + "*" < it->second)) {
                q.push(DATA({next2, cur.exp + "*"}));
                m.insert(make_pair(next2, cur.exp + "*"));
            }
        } else if (next2 == t && (answer.empty() || cur.exp + "*" < answer)) {
            answer = cur.exp + "*";
        }
        q.pop();
    }
    return (answer.empty()) ? "-1" : answer;
}

int main() {
    cout << logic() << "\n";
}