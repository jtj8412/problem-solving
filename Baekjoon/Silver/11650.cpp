//----------------------------------------------------------------------------------
// [ 좌표 정렬하기 ] https://www.acmicpc.net/problem/11650
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

struct COMPARE {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
        return (a.first == b.first) ? a.second > b.second : a.first > b.first;
    }
};

int main() {
    int N;
    priority_queue<pair<int,int>, vector<pair<int,int>>, COMPARE> pq;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        pair<int,int> p;
        scanf("%d %d", &p.first, &p.second);
        pq.push(p);
    }
    while (!pq.empty()) {
        printf("%d %d\n", pq.top().first, pq.top().second);
        pq.pop();
    }
}