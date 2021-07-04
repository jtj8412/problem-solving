/* 이상한 문자 만들기 */

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	const int diff = 'A' - 'a';

	for (int i = 0; i < s.size(); i += 2) {
		while (s[i] == ' ') i++;
		if (s[i] >= 'a') s[i] += diff;
		if (s[i + 1] >= 'A' && s[i + 1] <= 'Z') s[i + 1] -= diff;
	}

	return s;
}