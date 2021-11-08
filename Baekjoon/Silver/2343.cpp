//----------------------------------------------------------------------------------
// [ 기타 레슨 ] https://www.acmicpc.net/problem/2343
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main() {
    int mid = 0, n, m, arr[100000], l = 0, r = 0x7fffffff, answer = 0x7fffffff;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }
    while (l <= r) {
        int max_sum = 0, sum = 0, cnt = 1;
        mid = (l + r) >> 1; 
        for (int i = 0; i < n; ++i) {
            if (sum + arr[i] > mid) {
                max_sum = max(max_sum, sum);
                sum = 0;
                ++cnt;
            }
            sum += arr[i];
        }
        max_sum = max(max_sum, sum);
        if (cnt <= m) {
            r = mid - 1;
            answer = min(max_sum, answer);
        } else {
            l = mid + 1;
        }
    }
    printf("%d", answer);
}