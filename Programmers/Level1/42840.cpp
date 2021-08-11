//---------------------------------------------------------------------------------- 
// [ 모의고사 ] https://programmers.co.kr/learn/courses/30/lessons/42840
//
// n번 사람이 찍는방식은 각각 반복되는 규칙이 있음
// n번 사람의 i번째 문제 답 = num[n][i % 규칙길이]
//----------------------------------------------------------------------------------

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int num[3][10] = {{ 1, 2, 3, 4, 5 }, { 2, 1, 2, 3, 2, 4, 2, 5 }, { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 } };
	int len[] = { 5, 8, 10 }, correct[3] = {}, size = answers.size(), max = 0;

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (num[j][i % len[j]] == answers[i]) correct[j]++;
		}
	}
	
	for (int i = 0; i < 3; ++i) {
		if (correct[i] > max) max = correct[i];
	}

	for (int i = 0; i < 3; ++i) {
		if (correct[i] == max) answer.push_back(i + 1);
	}

	return answer;
}