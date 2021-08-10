//----------------------------------------------------------------------------------
// [ 소수 찾기 ] https://programmers.co.kr/learn/courses/30/lessons/12921
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