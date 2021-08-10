//----------------------------------------------------------------------------------
// [ 나누어 떨어지는 숫자 배열 ] https://programmers.co.kr/learn/courses/30/lessons/12910
//----------------------------------------------------------------------------------

#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
	vector<int> answer;
	int size = arr.size(), i;

	for (i = 0; i < size; ++i) {
		if (arr[i] % divisor == 0) answer.push_back(arr[i]);
	}
	sort(answer.begin(), answer.end());

	if (answer.size() == 0) answer.push_back(-1);
	return answer;
}