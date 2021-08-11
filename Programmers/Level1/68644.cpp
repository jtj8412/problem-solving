//----------------------------------------------------------------------------------
// [ 두 개 뽑아서 더하기 ] https://programmers.co.kr/learn/courses/30/lessons/68644
//----------------------------------------------------------------------------------

#include <vector>
using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> ans;
	int size = numbers.size(), arr[201] = {}, i, j;

	for (i = 0; i < size; ++i) {
		for (j = i + 1; j < size; ++j) {
			arr[numbers[i] + numbers[j]] = 1;
		}
	}

	for (int i = 0; i < 201; ++i) {
		if (arr[i]) ans.push_back(i);
	}

	return ans;
}