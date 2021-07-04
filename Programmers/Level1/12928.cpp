/* 약수의 합 */

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
	int answer = 0;
	int sqr = sqrt(n);
	
	for (int i = 1; i <= sqr; ++i) {
		if (n % i != 0) continue;
		answer += i;
		if (n / i != i) answer += n / i;
	}

	return answer;
}