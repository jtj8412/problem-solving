/* 서울에서 김서방 찾기 */

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
	string answer = "";
	const string kim = "Kim";
	int i = -1;

	for (i = 0; i < seoul.size(); ++i) {
		if (seoul[i].compare(kim) == 0)
			break;
	}
	
	answer = "김서방은 " + to_string(i) + "에 있다";

	return answer;
}