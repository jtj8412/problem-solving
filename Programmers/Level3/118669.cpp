#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> answer;
vector<map<int, int>> nodes;
vector<bool> is_start_nodes;
vector<bool> is_end_nodes;
vector<int> to_intensitiy_histories;

void travle(int start_node)
{
	queue<pair<int, int>> q; // from_node, from_intensity

	q.push(make_pair(start_node, 0));

	while (!q.empty())
	{
		pair<int, int> elem = q.front(); q.pop();
		int from_node = elem.first;
		int from_intensity = elem.second;

		if (to_intensitiy_histories[from_node] < from_intensity)
			continue;

		for (auto& iter : nodes[from_node])
		{
			int to_node = iter.first;
			int to_intensity = iter.second;

			if (is_start_nodes[to_node])
				continue;

			int next_intensity = max(from_intensity, to_intensity);

			int to_intensity_hist = to_intensitiy_histories[to_node];
			if (to_intensity_hist != 0 && next_intensity >= to_intensity_hist)
				continue;

			to_intensitiy_histories[to_node] = next_intensity;

			if (is_end_nodes[to_node])
				continue;

			q.push(make_pair(to_node, next_intensity));
		}
	}
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits)
{
	vector<int> answer;
	answer.resize(2, 0);
	answer[1] = INT_MAX;

	nodes.resize(n + 1);
	for (int i = 0; i < paths.size(); ++i)
	{
		nodes[paths[i][0]][paths[i][1]] = paths[i][2];
		nodes[paths[i][1]][paths[i][0]] = paths[i][2];
	}

	is_start_nodes.resize(n + 1, false);
	for (int i = 0; i < gates.size(); ++i)
		is_start_nodes[gates[i]] = true;

	is_end_nodes.resize(n + 1, false);
	for (int i = 0; i < summits.size(); ++i)
		is_end_nodes[summits[i]] = true;

	to_intensitiy_histories.resize(n + 1, 0);

	for (int i = 0; i < gates.size(); ++i)
		travle(gates[i]);

	sort(summits.begin(), summits.end());

	for (int i = summits.size() - 1; i >= 0; --i)
	{
		int node = summits[i];
		int intensity_hist = to_intensitiy_histories[node];
		if (intensity_hist != 0 && intensity_hist <= answer[1])
		{
			answer[0] = node;
			answer[1] = intensity_hist;
		}
	}

	return answer;
}

int main()
{
	vector<int> result = solution(
		5,
		{{5, 4, 1}, {5, 3, 1}, {3, 2, 2}, {4, 2, 1}, {2, 1, 1}},
		{ 1 },
		{ 5, 4, 2, 3 }
	);

	for (int i = 0; i < result.size(); ++i)
	{
		cout << "result" << i << ": " << result[i] << endl;
	}

	return 0;
}