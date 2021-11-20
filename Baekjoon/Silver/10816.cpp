//----------------------------------------------------------------------------------
// [ 숫자 카드 2 ] https://www.acmicpc.net/problem/10816
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int N, M;
map<int, int> m;

int main() {
    int val;
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> val;
        m[val]++;
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> val;
        cout << m[val] << " ";
    }
}

