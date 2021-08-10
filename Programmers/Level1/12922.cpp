//----------------------------------------------------------------------------------
// [ 수박수박수박수박수박수? ] https://programmers.co.kr/learn/courses/30/lessons/12922
//----------------------------------------------------------------------------------

#include <string>
using namespace std;

string solution(int n) {
	string answer;
	for (int i = 2; i <= n; i += 2) answer += "수박";
	if (n & 1) answer += "수";
	return answer;
}