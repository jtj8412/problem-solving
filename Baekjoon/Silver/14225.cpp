//----------------------------------------------------------------------------------
// [ 부분수열의 합 ] https://www.acmicpc.net/problem/14225
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int N;
bool visited[2000001];
vector<int> vec;

void logic(int idx, int val) {
    if (idx == N) {
        visited[val] = 1;
    } else {
        logic(idx + 1, val);
        logic(idx + 1, val + vec[idx]);
    }
}

int main() {
    scanf("%d", &N);
    vec.resize(N);
    for (int i = 0; i < N; ++i) scanf("%d", &vec[i]);
    logic(0, 0);
    for (int i = 1; i < 2000001; ++i) {
        if (!visited[i]) {
            printf("%d\n", i);
            break;
        }
    }
}