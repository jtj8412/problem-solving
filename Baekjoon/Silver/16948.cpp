//----------------------------------------------------------------------------------
// [ 데스 나이트 ] https://www.acmicpc.net/problem/16948
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 1, -2, 2, -1, 1}, dy[] = {-2, -2, 0, 0, 2, 2};
int visited[200][200] = {}, n, r1, c1, r2, c2;
     
int logic() {
    queue<pair<int,int>> q;
    int size, cnt, answer = 1;
    q.push(make_pair(r1, c1));
    visited[c1][r1] = 1;
    size = 1;
    while (!q.empty()) {
        pair<int,int> cur = q.front(); q.pop();
        for (int i = 0; i < 6; ++i) {
            pair<int,int> next = make_pair(cur.first + dx[i], cur.second + dy[i]);
            if (next.first < 0 || next.second < 0 || next.first >= n || next.second >= n || visited[next.second][next.first]) continue;
            if (next.first == r2 && next.second == c2) return answer;
            q.push(make_pair(next.first, next.second));
            visited[next.second][next.first] = 1;
        }
        if (++cnt == size) {
            size = q.size();
            cnt = 0;
            ++answer;
        }
    }
    return -1;
}

int main() {
    scanf("%d", &n);
    scanf("%d %d %d %d", &c1, &r1, &c2, &r2);
    printf("%d", logic());
}