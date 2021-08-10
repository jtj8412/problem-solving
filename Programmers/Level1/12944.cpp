//----------------------------------------------------------------------------------
// [ 평균 구하기 ] https://programmers.co.kr/learn/courses/30/lessons/12944
//----------------------------------------------------------------------------------

#include <vector>
using namespace std;

double solution(vector<int> arr) {
	double answer = 0;

	for (int i = 0; i < arr.size(); ++i)
		answer += arr[i];
	answer /= arr.size();

	return answer;
}