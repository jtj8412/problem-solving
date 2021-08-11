//----------------------------------------------------------------------------------
// [ 3진법 뒤집기 ] https://programmers.co.kr/learn/courses/30/lessons/68935
//----------------------------------------------------------------------------------

#include <string>
using namespace std;

int solution(int n) {
	int answer = 0, mod = 43046721, mul = 1, idx = 0, div, i;
	string s_three = "";

	for (i = 16; i >= 0; i--) {
		div = n / mod;
		s_three += (div + '0');
		n -= mod * div;
		mod /= 3;
	}

	while (s_three[idx++] == '0');

	for (i = idx - 1; i < (int)s_three.length(); ++i) {
		answer += mul * (s_three[i] - '0');
		mul *= 3;
	}

	return answer;
}