//----------------------------------------------------------------------------------
// [ 문자열 내 p와 y의 개수 ] https://programmers.co.kr/learn/courses/30/lessons/12916
//----------------------------------------------------------------------------------

#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
	const char CH[] = { 'p', 'P', 'y', 'Y' };
	int cnt[4] = { 0, };
	int length = s.length();

	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (CH[j] == s[i]) {
				cnt[j]++;
				break;
			}
		}
	}

	if (cnt[0] + cnt[1] == cnt[2] + cnt[3]) return true;
	return false;
}