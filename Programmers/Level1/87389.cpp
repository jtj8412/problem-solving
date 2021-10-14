//----------------------------------------------------------------------------------
// [ 나머지가 1이 되는 수 찾기 ] https://programmers.co.kr/learn/courses/30/lessons/87389
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int len = sqrt(n);
    for (int i = 2; i <= len; ++i) {
        if ((n - 1) % i == 0) return i;
    }
    return n - 1;
}