/* 행렬의 덧셈 */

#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	int n1 = arr1.size();
	int n2 = arr1[0].size();

	for (int i = 0; i < n1; ++i)
	{
		for (int j = 0; j < n2; ++j)
			arr1[i][j] += arr2[i][j];
	}

	return arr1;
}