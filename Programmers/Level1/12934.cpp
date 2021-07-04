/* 정수 제곱근 판별 */

#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
	long long answer = 0;
	long long sqr = sqrt(n);
	
	if (sqr * sqr != n) return -1;

	return (sqr + 1) * (sqr + 1);
}