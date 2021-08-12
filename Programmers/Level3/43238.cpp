//----------------------------------------------------------------------------------
// [ 입국심사 ] https://programmers.co.kr/learn/courses/30/lessons/43238
//
// 1. 최솟값(0), 최댓값(1e19)를 양 끝으로 이분탐색 값을 심사에 걸리는 시간으로 설정
// 2. 1에서 설정한 심사시간 기준으로 처리할 수 있는 인원이 n보다 큰지 작은지에 따라
//    이분탐색 재진행
// 3-1. 임의의 심사시간에 대해 처리할 수 있는 인원이 n과 같은 경우
//      가장 오래 작업한 심사위원의 작업시간이 정답
// 3-2. 심사위원이 모두 필요하지 않을 때, l > r 인 left가 더 커지는 경우가 나오며
//      l이 정답
//----------------------------------------------------------------------------------

#include <vector>
using namespace std;

long long solution(int n, vector<int> times) {
    long long l = 0LL, r = 1000000000000000000LL, mid, sum = 0, max = 0, div, mul;

    while (sum != n && l <= r) {
        mid = (l + r) >> 1;
        sum = max = 0;
        for (auto time : times) {
            div = mid / time;
            sum += div;
            if (sum > n) break;
            if ((mul = div * time) > max) max = mul;
        }
        if (sum < n) l = mid + 1;
        else if (sum > n) r = mid - 1;
    }
    
    if (l > r) return l;
    return max;
}