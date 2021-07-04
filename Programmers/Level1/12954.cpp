/* x만큼 간격이 있는 n개의 숫자 */

#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
	vector<long long> answer;
	long long cur = x;

	for (int i = 0; i < n; ++i) {
		answer.push_back(cur);
		cur += x;
	}

	return answer;
}