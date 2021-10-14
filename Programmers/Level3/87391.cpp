//----------------------------------------------------------------------------------
// [ 공 이동 시뮬레이션 ] https://programmers.co.kr/learn/courses/30/lessons/87391
//
// 목적지에서부터 역으로 이동하여 풀이하는 방법
//
// 만약 ← 방향으로 1번 이동한 결과가 좌측벽에 붙은거라면, 그 이전의 위치는 원래 좌측벽에 붙
// 어 있었을 경우와 좌측벽과 한 칸 떨어져있었을 경우로 분기가 나뉘게 된다.
//
// 이처럼 이동한 결과가 벽에 붙은거라면 분기가 늘어나게 되며 이 분기의 범위를 사각형의 범위로
// 정의할 수 있다. (left top right bottom)
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    int l = y, r = y, t = x, b = x;
    
    for (int i = queries.size() - 1; i >= 0; --i) {
        int cmd = queries[i][0];
        int val = queries[i][1];
        
        if (cmd == 0) { // 좌측
            if (l == 0) {
                r = min(m - 1, r + val);
            } else {
                l += val;
                r = min(m - 1, r + val);
            }
        } else if (cmd == 1) { // 우측
            if (r == m - 1) {
                l = max(0, l - val);
            } else {
                r -= val;
                l = max(0, l - val);
            }
        } else if (cmd == 2) { // 상단
            if (t == 0) {
                b = min(n - 1, b + val);
            } else {
                t += val;
                b = min(n - 1, b + val);
            }
        } else if (cmd == 3) { // 하단
            if (b == n - 1) {
                t = max(0, t - val);
            } else {
                b -= val;
                t = max(0, t - val);
            }
        }
        if (r < 0 || l > m - 1 || b < 0 || t > n - 1) return 0; // 불가능
    }
    return (long long)(r - l + 1) * (b - t + 1);
}