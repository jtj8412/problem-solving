//----------------------------------------------------------------------------------
// [ 구간 나누기 2 ] https://www.acmicpc.net/problem/13397
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, l = 0, r = 10000, mid, arr[5000], cnt, max_, min_, max_val, answer = 0x7fffffff;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }

    while (l <= r) {
        mid = (l + r) >> 1;
        max_val = 0;
        min_ = max_ = arr[0];
        cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[i] - min_ > mid || max_ - arr[i] > mid) {
                max_val = max(max_val, max_ - min_);
                if (++cnt > m) break;
                max_ = min_ = arr[i];
            }
            min_ = min(min_, arr[i]);
            max_ = max(max_, arr[i]);
        }
        

        if (cnt > m) {
            l = mid + 1;
        } else {
            max_val = max(max_val, max_ - min_);
            answer = min(answer, mid);
            r = mid - 1;
        }
    }
    
    printf("%d", answer);
}