/* [1차] 비밀지도 */

#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	int n1 = arr1.size();
	int sum, bit, bit_max = pow(2, n -1);

	for (int i = 0; i < n1; ++i) {
		string tmp;
		sum = arr1[i] | arr2[i];
		bit = bit_max;

		for (int j = 0; j < n; j++) {
			if ((sum & bit) != 0)
				tmp.push_back('#');
			else
				tmp.push_back(' ');
			bit >>= 1;
		}

		answer.push_back(tmp);
	}
	return answer;
}