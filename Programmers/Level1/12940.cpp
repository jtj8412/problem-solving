//----------------------------------------------------------------------------------
// [ 최대공약수와 최소공배수 ] https://programmers.co.kr/learn/courses/30/lessons/12940
//
// 유클리드 호제법
// 105와 42의 최대공약수 21 = (3*7)
// 105-42 = (5-2)(3*7) = 3*(3*7)
// 즉 a와 b의 최대공약수와 b와 (a-b)의 최대공약수는 동일하다 == b와 (a % b)의 최대공약수는 동일하다
// 나누어 떨어질때까지 위의 동작을 반복하며, 그 시점에 나눈 값이 최대공약수이다
//----------------------------------------------------------------------------------

#include <vector>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int lcm(int a, int b, int gcd_) {
	return a * b / gcd_;
}

vector<int> solution(int n, int m) {
	vector<int> answer(2);
	int gcd_ = gcd(n, m);

	answer[0] = gcd_;
	answer[1] = lcm(n, m, gcd_);

	return answer;
}