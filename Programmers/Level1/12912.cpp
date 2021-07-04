/* 두 정수 사이의 합 */

#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) 
{
	long long answer = 0;
	
	if (a == b) return a;

	long long len = (abs(a - b) + 1) / 2;
	long long hap = a + b;

	answer = hap * len;

	if ((abs(a - b) + 1) % 2 != 0) answer += (a + b) / 2;

	return answer;
}