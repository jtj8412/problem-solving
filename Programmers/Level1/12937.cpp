/* 짝수와 홀수 */

#include <string>
#include <vector>

using namespace std;

string solution(int num) {
	const string odd = "Odd", even = "Even";

	if (num % 2 == 0) return even;
	return odd;
}