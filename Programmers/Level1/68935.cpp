/* 3천번 뒤집기 */

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	int mod_val = 43046721;
	int mul_val = 1;
	int idx = 0;
	string base3 = "";

	for (int i = 16; i >= 0; i--) {
		int div = n / mod_val;

		string tmp = { (char)(div + '0') };
		base3.append(tmp);
		n -= mod_val * div;
		mod_val /= 3;
	}

	while (base3[idx++] == '0');

	for (int i = idx - 1; i < (int)base3.length(); ++i) {
		answer += mul_val * (base3[i] - '0');
		mul_val *= 3;
	}

	return answer;
}