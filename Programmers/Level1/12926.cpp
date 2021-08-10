//----------------------------------------------------------------------------------
// [ 시저 암호 ] https://programmers.co.kr/learn/courses/30/lessons/12926
//----------------------------------------------------------------------------------

#include <string>
#include <vector>
using namespace std;

string solution(string s, int n) {
	for (int i = 0, size = s.size(), sum; i < size; ++i) {
		if (s[i] == ' ') continue;
		if (s[i] >= 'a') { 
			if (s[i] + n > 'z') s[i] -= 26; 
		}
		else if (s[i] + n > 'Z') 
			s[i] -= 26;
		s[i] += n;
	}
	return s;
}