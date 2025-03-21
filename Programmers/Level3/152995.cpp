#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> max_mate_by_atti;

int solution(vector<vector<int>> scores) {
	int answer = 1;

	max_mate_by_atti.assign(100002, 0);

	int wonho_atti = scores[0][0];
	int wonho_mate = scores[0][1];
	int wonho_sum = wonho_atti + wonho_mate;

	// atti 에서 나올 수 있는 최대 mate 수 설정
	for (int i = 0; i < scores.size(); ++i)
	{
		int atti = scores[i][0];
		int mate = scores[i][1];

		max_mate_by_atti[atti] = max(mate, max_mate_by_atti[atti]);
	}

	// atti + n 에서 나올 수 있는 최대 mate 수 설정
	for (int i = 100000; i >= 0; --i)
	{
		if (max_mate_by_atti[i] < max_mate_by_atti[i + 1])
			max_mate_by_atti[i] = max_mate_by_atti[i + 1];
	}

	if (wonho_mate < max_mate_by_atti[wonho_atti + 1])
		return -1;

	// 사원 순위 나열 (인센티브 못받는 사원 필터링)
	priority_queue<int> pq;
	
	for (int i = 0; i < scores.size(); ++i)
	{
		int atti = scores[i][0];
		int mate = scores[i][1];

		if (mate < max_mate_by_atti[atti + 1])
			continue;

		pq.push(atti + mate);
	}

	// 원호 순위 찾기
	while (!pq.empty())
	{
		int sum = pq.top();

		if (sum == wonho_sum)
			break;

		answer++;

		pq.pop();
	}

	return answer;
}

int main()
{
	int result = solution({ {2,2}, {1,4}, {3,2}, {3,2}, {2,1} });

	cout << result << endl;

	return 0;
}