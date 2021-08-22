//----------------------------------------------------------------------------------
// [ 숫자 게임 ] https://programmers.co.kr/learn/courses/30/lessons/12987
//
// A의 임의의 숫자를 이길 수 있는 B의 숫자 중 가장 작은 숫자를 택하는 방식
// 위의 방식대로 가장 작은 숫자를 탐색하는 중 지나치는 숫자는 스택(stk)에 담아서 필요시 사용
//----------------------------------------------------------------------------------

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0, N = A.size(), a, b = 0, stk = 0;

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    B.push_back(-1);

    for (a = 0; b < N && a < N; ++a) {
        if (B[b] > A[a]) {
            for (; B[b+1] > A[a]; ++b) ++stk;
            ++answer;
            ++b;
        } else if (stk) {
            ++answer;
            --stk;
        }
    }
    if (N - a < stk) stk = N - a;
    answer += stk;

    return answer;
}