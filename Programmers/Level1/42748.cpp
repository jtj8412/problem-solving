/* K번째수 */

#include <string>
#include <vector>

using namespace std;

vector<int>* newArray(vector<int>& arr, int start, int end)
{
	vector<int>* ret = new vector<int>();

	for (int i = start; i <= end; ++i)
		ret->push_back(arr[i]);

	return ret;
}

void sortArray(vector<int>& arr)
{
	int tmp;

	for (unsigned int i = 0; i < arr.size() - 1; ++i){
		for (unsigned int j = i + 1; j < arr.size(); ++j){
			if (arr[i] < arr[j]) continue;

			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (unsigned int i = 0; i < commands.size(); ++i){
		vector<int>* arr = newArray(array, commands[i][0] - 1, commands[i][1] - 1);
		sortArray(*arr);
		answer.push_back((*arr)[commands[i][2] - 1]);
	}

	return answer;
}