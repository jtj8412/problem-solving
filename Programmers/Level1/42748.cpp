//----------------------------------------------------------------------------------
// [ k번째수 ] https://programmers.co.kr/learn/courses/30/lessons/42748
//
// 1. 우선순위큐에 오름차순으로 명령(commands)의 인덱스에 맞게 수를 적재
// 2. 큐에 n번째에 위치한 수가 k번째수
//----------------------------------------------------------------------------------

#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0, size = commands.size(); i < size; ++i) {
		for (int j = commands[i][0] - 1; j < commands[i][1]; ++j) pq.push(array[j]);
		for (int j = 1; j < commands[i][2]; ++j) pq.pop();
		answer.push_back(pq.top());
		while (!pq.empty()) pq.pop();
	}

	return answer;
}