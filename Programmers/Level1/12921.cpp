/* 소수 찾기 */

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int arr[1000001] = {};

int solution(int n) {
	int answer = 0;
 	int len = sqrt(n);

	for (int i = 2; i <= len; ++i) {
		int len2 = (n / i);
		for (int j = i; j <= len2; j++)
			arr[i * j] = 1;
	}

	for (int i = 2; i <= n; ++i) {
		if (!arr[i]) answer++;
	}

	return answer;
}