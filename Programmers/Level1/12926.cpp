/* 시저 암호 */

#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
	string answer = "";

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == ' ') {
			answer.push_back(' ');
		}
		else
		{
			int num = s[i] - ((s[i] >= 'a') ? 'a' : 'A');
			num = (num + n) % 26;
			num += (s[i] >= 'a') ? 'a' : 'A';
			answer.push_back((char)num);
		}
	}


	return answer;
}