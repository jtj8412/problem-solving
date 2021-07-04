/* 문자열 내림차순으로 배치하기 */

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	int len = s.size();
	int max_idx = 0;

	for (int i = 0; i < len; ++i) {
		max_idx = 0;
		for (int j = 1; j < s.size(); ++j) {
			if (s[max_idx] < s[j]) max_idx = j;
		}
		answer.push_back(s[max_idx]);
		s.erase(max_idx, 1);
	}

	return answer;
}