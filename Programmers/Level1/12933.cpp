//----------------------------------------------------------------------------------
// [ 정수 내림차순으로 배치하기 ] https://programmers.co.kr/learn/courses/30/lessons/12933
//
// 1. n이 이루고 있는 각 숫자들의 갯수를 세어 배열에 저장
// 2. 배열에서 9부터 하나씩 숫자를 꺼내어 정답을 구성
//----------------------------------------------------------------------------------

#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
	long long answer = 0;
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