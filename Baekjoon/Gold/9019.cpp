//----------------------------------------------------------------------------------
// [ DSLR ] https://www.acmicpc.net/problem/9019
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

struct DATA {
    int n;
    string s;
};

int command(int val, int cmd) {
    switch (cmd) {
    case 0: return (val * 2) % 10000;
    case 1: return (val == 0) ? 9999 : val - 1;
    case 2: return ((val * 10) % 10000) + (val / 1000);
    case 3: return (val / 10) + (val % 10) * 1000;
    }
    return -1;
}

void logic(int a, int b) {
    queue<DATA> q;
    int visited[10000] = {};
    q.push(DATA{a, ""});
    visited[a] = 1;
    while (!q.empty()) {
        DATA& cur = q.front();
        for (int i = 0; i < 4; ++i) {
            int next = command(cur.n, i);
            if (visited[next]) continue;
            string s = cur.s;
            switch (i) {
            case 0: s += 'D'; break;
            case 1: s += 'S'; break;
            case 2: s += 'L'; break;
            case 3: s += 'R'; break;
            }
            if (next == b) {
                cout << s << "\n";
                return;
            }
            q.push({next, s});
            visited[next] = 1;
        }
        q.pop();
    }
}

int main() {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        logic(a, b);
    }
}