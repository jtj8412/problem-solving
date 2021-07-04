/* 나누어 떨어지는 숫자 배열 */

#include <string>
#include <vector>
#include <list>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
	vector<int> answer;
	list<int> answerList;
	list<int>::iterator iter, iterEnd = answerList.end();
	int size = arr.size();

	if (arr[0] % divisor == 0) answerList.push_back(arr[0]);

	for (int i = 1; i < size; ++i) {
		if (arr[i] % divisor != 0) continue;

		for (iter = answerList.begin(); iter != iterEnd; ++iter) {
			if (*iter > arr[i]) {
				answerList.insert(iter, arr[i]);
				break;
			}
		}
		if (iter == iterEnd) answerList.push_back(arr[i]);
	}

	for (iter = answerList.begin(); iter != iterEnd; ++iter)
		answer.push_back(*iter);

	if (answer.empty()) answer.push_back(-1);

	return answer;
}