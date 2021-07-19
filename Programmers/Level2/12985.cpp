/* 예상 대진표 */

#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while (a != b) {
        a = (a + 1) * 0.5;
        b = (b + 1) * 0.5;
        ++answer;
    }

    return answer;
}