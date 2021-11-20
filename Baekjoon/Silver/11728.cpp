//----------------------------------------------------------------------------------
// [ 배열 합치기 ] https://www.acmicpc.net/problem/11728
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int arr[1000000] = {};

int main() {
    int n, m, a = 0, b = 0, val;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", arr + i);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &val);
        while (a != n && arr[a] < val) printf("%d ", arr[a++]);
        printf("%d ", val);
    }
    while (a != n) printf("%d ", arr[a++]);
}

