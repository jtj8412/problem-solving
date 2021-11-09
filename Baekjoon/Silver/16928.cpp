//----------------------------------------------------------------------------------
// [ 뱀과 사다리 게임 ] https://www.acmicpc.net/problem/16928
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, arr[107] = {}, visited[107] = {}, val1, val2, answer = 0x7fffffff;
    queue<pair<int,int>> q;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n + m; ++i) {
        scanf("%d %d", &val1, &val2);
        arr[val1] = val2;
    }
    q.push(make_pair(1, 0));
    visited[1] = 1;
    while (!q.empty()) {
        pair<int,int> cur = q.front(); q.pop();
        for (int i = 1; i < 7; ++i) {
            int next = (arr[cur.first + i]) ? arr[cur.first + i] : cur.first + i;
            if (visited[next]) continue;
            if (next >= 100) {
                answer = min(answer, cur.second + 1);
                break;
            }
            q.push(make_pair(next, cur.second + 1));
            visited[next] = 1;
        }
    }
    printf("%d", answer);
}