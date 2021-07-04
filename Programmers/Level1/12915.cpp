/* 문자열 내 마음대로 정렬하기 */

#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
	vector<string>::iterator max, iter;
	int len = strings.size();

	for (int i = 0; i < len; ++i) {
		iter = max = strings.begin();
		for (iter++; iter != strings.end(); iter++) {
			char a = (*iter)[n]; char b = (*max)[n];
			int res = a - b;
			if ((res == 0 && (*iter).compare((*max)) < 0) || res < 0)
				max = iter;
		}
		answer.push_back((*max));
		strings.erase(max);
	}
    return answer;
}