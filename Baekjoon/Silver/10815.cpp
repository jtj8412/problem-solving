//----------------------------------------------------------------------------------
// [ 숫자 카드 ] https://www.acmicpc.net/problem/10815
//
// 이분 탐색
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int N, M, arr[500000] = {};

int logic(int val) {
    int l = 0, r = N - 1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (arr[mid] == val) return 1;
        if (arr[mid] > val) r = mid - 1;
        else l = mid + 1;
    }
    return 0;
}

int main() {
    int val;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", arr + i);
    }
    sort(arr, arr + N);
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d", &val);
        printf("%d ", logic(val));
    }
}

