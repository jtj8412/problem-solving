//----------------------------------------------------------------------------------
// [ 약수의 합 ] https://programmers.co.kr/learn/courses/30/lessons/12928
//
// 20: (1*20)=(2*10)=(4*5) <-> (5*4)=(10*2)=(20*1)
// 위의 예와 같이 n의 제곱근을 기준으로 약수가 대칭되어 보여지는 것을 이용한다
// 단 n=16 경우 대칭 기준점이 4x4이므로 위의 방식대로라면 약수에 4가 두개 생김을 주의
//----------------------------------------------------------------------------------

#include <cmath>
using namespace std;

int solution(int n) {
	int answer = 0, len = sqrt(n), i;
	for (i = 1; i <= len; ++i) {
		if (n % i != 0) continue;
		answer += i + (n / i);
	}
	if (len * len == n) answer -= len;
	return answer;
}