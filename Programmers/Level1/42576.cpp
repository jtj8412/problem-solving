//----------------------------------------------------------------------------------
// [ 완주하지 못한 선수 ] https://programmers.co.kr/learn/courses/30/lessons/42576
//
// 1. 해시맵에 참가자(participant) 및 동명이인 수 저장
// 2. 완주자(completion)를 key로 해시맵에 있는 참가자 탐색 및 감소
// 3. 2결과 0이되면 해시맵에서 삭제
// 4. 해시맵에 유일하게 남은 참가자가 '완주하지 못한 선수'
//----------------------------------------------------------------------------------

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion)  {
	unordered_map<string, int> dict;
	unordered_map<string, int>::iterator iter;

	for (auto s : participant) { 
		++dict[s];
	}
	for (auto s : completion) {
		if (--((iter = dict.find(s))->second) == 0) dict.erase(iter);
	}

	return dict.begin()->first;
}