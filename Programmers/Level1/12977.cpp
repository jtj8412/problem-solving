//----------------------------------------------------------------------------------
// [ 소수 만들기 ] https://programmers.co.kr/learn/courses/30/lessons/12977
// 
// 1. 1~3000 까지의 소수 정보를 설정한다
// 2. 주어진 배열의 숫자 중 세개로 만들 수 있는 소수를 모두 탐색
//----------------------------------------------------------------------------------

#include <vector>
#include <cmath>
#define PRIME_MAX 3000
using namespace std;

int solution(vector<int> nums) {
	int answer = 0;
	int prime[PRIME_MAX + 1] = {};
	int prime_sqrt = sqrt(PRIME_MAX);
    
	for (int i = 2; i <= prime_sqrt; ++i) {
		if (prime[i] == 1) continue;
		for (int j = i; i * j <= PRIME_MAX; ++j)
			prime[i * j] = 1;
	}
    
	for (int i = 0; i < nums.size() - 2; i++) {
		for (int j = i + 1; j < nums.size() - 1; j++) {
			for (int k = j + 1; k < nums.size(); k++) {
				int sum = nums[i] + nums[j] + nums[k];
				if (prime[sum] == 0)
					answer++;
			}
		}
	}
    
	return answer;
}
