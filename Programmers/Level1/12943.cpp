/* 콜라츠 추측 */

#include <vector>

using namespace std;

int solution(int num) {
	long answer = 0;
	long long n = num;
	while (n != 1 && answer != 500)
	{
		if (n % 2 == 0) n /= 2;
		else n = n * 3 + 1;
		answer++;
	}

	if (answer == 500) return -1;

	return answer;
}