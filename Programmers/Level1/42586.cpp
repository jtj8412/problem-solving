/* 기능개발 */

#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int idx = 0, cnt = 0, dest;
	int len = speeds.size();
	int day = (int)ceil((100 - progresses[idx]) / (float)speeds[idx]);

	while (idx < len) {
		dest = (int)ceil((100 - progresses[idx]) / (float)speeds[idx]);
		
		if (dest > day) {
			answer.push_back(cnt);
			cnt = 1;
			day = dest;
		}
		else {
			cnt++;
		}
		idx++;
	}

	answer.push_back(cnt);

	return answer;
}