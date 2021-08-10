//---------------------------------------------------------------------------------- 
// [ 같은 숫자는 싫어 ] https://programmers.co.kr/learn/courses/30/lessons/12906
//----------------------------------------------------------------------------------

#include <vector>
using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;
	int keep = arr[0];
	int size = arr.size();

	for (int i = 1; i < size; ++i) {
		if (arr[i] == keep) continue;
		answer.push_back(keep);
		keep = arr[i];
	}
	answer.push_back(keep);

	return answer;
}