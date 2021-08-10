//----------------------------------------------------------------------------------
// [ 문자열 내림차순으로 배치하기 ] https://programmers.co.kr/learn/courses/30/lessons/12917
//----------------------------------------------------------------------------------

#include <string>
#include <algorithm>
using namespace std;

string solution(string s) {
	sort(s.begin(), s.end(), [](const char a, const char b)->bool{return a > b;});
	return s;
}