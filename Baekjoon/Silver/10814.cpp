//----------------------------------------------------------------------------------
// [ 나이순 정렬 ] https://www.acmicpc.net/problem/10814
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

struct DATA {
    int age, idx;
    char name[101];
};

struct COMPARE {
    bool operator()(const DATA& a, const DATA& b) {
        return (a.age == b.age) ? a.idx > b.idx : a.age > b.age;
    }
};

int main() {
    int N;
    priority_queue<DATA, vector<DATA>, COMPARE> pq;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        DATA data;
        scanf("%d %s", &data.age, data.name);
        data.idx = i;
        pq.push(data);
    }
    while (!pq.empty()) {
        printf("%d %s\n", pq.top().age, pq.top().name);
        pq.pop();
    }
}