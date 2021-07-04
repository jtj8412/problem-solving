/* 같은 숫자는 싫어 */

#include <vector>
#include <iostream>

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