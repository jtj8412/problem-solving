//----------------------------------------------------------------------------------
// [ 문자열을 정수로 바꾸기 ] https://programmers.co.kr/learn/courses/30/lessons/12925
//----------------------------------------------------------------------------------

#include <string>
#include <vector>

using namespace std;

int solution(string s) 
{
	if (s[0] == '-') return atoi(s.c_str() + 1) * -1;
	else if (s[1] == '+') return atoi(s.c_str() + 1);
	return stoi(s);
}