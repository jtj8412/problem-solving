/* 정수 내림차순으로 배치하기 */

#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
	long long answer = 0;
	long long mul = 1;
	int arr[10] = {};

	while (n != 0) {
		arr[n % 10]++;
		n /= 10;
	}

	for (int i = 9; i >= 0; --i) {
		while (arr[i] != 0) {
			answer = (answer + i) * 10;
			arr[i]--;
		}
	}
    
	answer /= 10;

	return answer;
}