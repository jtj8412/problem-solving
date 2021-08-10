//----------------------------------------------------------------------------------
// [ 문자열 다루기 기본 ] https://programmers.co.kr/learn/courses/30/lessons/12918
//----------------------------------------------------------------------------------

#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
	int length = s.length();

	if (length != 4 && length != 6) return false;

	for (int i = 0; i < length; ++i)
	{
		if (!(s[i] >= '0' && s[i] <= '9')) return false;
	}

	return true;
}