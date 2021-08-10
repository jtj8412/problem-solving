//----------------------------------------------------------------------------------
// [ 소수 찾기 ] https://programmers.co.kr/learn/courses/30/lessons/12921
//
// 1. 2부터 차례대로 소수인지 여부 표시
// 2. i가 소수일 경우 i의 j배는 소수가 아님(1)을 표시
// 3. 2부터 n까지 소수(0)의 개수를 센다
//----------------------------------------------------------------------------------

#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
	int answer = 0, len = sqrt(n), len2, i, j, arr[1000001] = {};

	for (i = 2; i <= len; ++i) {
		for (j = i; j <= n; j += i) arr[j] = 1;
	}
	for (int i = 2; i <= n; ++i) {
		if (!arr[i]) answer++;
	}

	return answer;
}