//----------------------------------------------------------------------------------
// [ 2016년 ] https://programmers.co.kr/learn/courses/30/lessons/12901
//----------------------------------------------------------------------------------

#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
	const int DATE[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	const string DAY[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int day = 4;

	for (int i = 0; i < a - 1; ++i)
		day += DATE[i];
	day += b;

	return DAY[day % 7];
}