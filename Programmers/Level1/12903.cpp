//----------------------------------------------------------------------------------
// [ 가운데 글자 가져오기 ] https://programmers.co.kr/learn/courses/30/lessons/12903
//----------------------------------------------------------------------------------

#include <string>
using namespace std;

string solution(string s) {
	string ans;
	if (s.length() % 2 == 0) ans += s[s.length() / 2 - 1];
	ans += s[s.length() / 2];
	return ans;
}