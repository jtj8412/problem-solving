//----------------------------------------------------------------------------------
// [ 두 정수 사이의 합 ] https://programmers.co.kr/learn/courses/30/lessons/12912
//
// 3+4+5...10
// 	= (3+10) + (4+9) + (5+8) + (6+7) 
//	= 13 * 4 
//	= (a+b) * len
//----------------------------------------------------------------------------------

#include <string>
#include <vector>
using namespace std;

long long solution(int a, int b) 
{
	long long answer = 0, len = (abs(a - b) + 1) / 2, hap = a + b;

	answer = hap * len;
	if ((abs(a - b) + 1) % 2 != 0) answer += (a + b) / 2;

	return answer;
}