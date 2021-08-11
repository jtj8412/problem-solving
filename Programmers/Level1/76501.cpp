//----------------------------------------------------------------------------------
// [ 음양 더하기 ] https://programmers.co.kr/learn/courses/30/lessons/76501
//----------------------------------------------------------------------------------

#include <vector>
using namespace std;

int solution(vector<int> abs, vector<bool> signs) {
	int answer = 0;
	int len = abs.size();

	for (int i = 0; i < len; ++i)
	{
		if (!signs[i]) answer += -abs[i];
		else answer += abs[i];
	}

	return answer;
}