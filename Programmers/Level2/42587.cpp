/* 프린터 */

#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0, num[10] = {};
	int size = priorities.size(), destCnt = 0, destIdx = 10;

	for (int i = 0; i < size; ++i)
		num[priorities[i]]++;

	if (answer == destCnt) {
		while (num[--destIdx] == 0);

		destCnt += num[destIdx];
	}

	for (int i = 0 ;; i++) {
		if (i == size) i = 0;

		if (destIdx == priorities[i]) {
			answer++;

			if (answer == destCnt) {
				while (num[--destIdx] == 0);
				destCnt += num[destIdx];
			}

			if (i == location) break;
		}
	}

	return answer;
}