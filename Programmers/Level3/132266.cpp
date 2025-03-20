#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct NODE_INFO
{
	int node, step;
};

vector<set<int>> nodes;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
	vector<int> answer;

	nodes.resize(n + 1);
	for (int i = 0; i < roads.size(); ++i)
	{
		int from = roads[i][0], to = roads[i][1];
		nodes[from].insert(to);
		nodes[to].insert(from);
	}

	queue<NODE_INFO> q;
	q.push({ destination, 0 });

	vector<int> visited;
	visited.assign(n + 1, -1);
	visited[destination] = 0;

	while (!q.empty())
	{
		const NODE_INFO& elem = q.front();
		int node = elem.node;
		int step = elem.step;

		int next_step = step + 1;

		for (int next_node : nodes[node])
		{
			if (visited[next_node] != -1)
				continue;

			visited[next_node] = next_step;

			if (next_node == destination)
				break;

			q.push({ next_node, next_step });
		}

		q.pop();
	}

	for (int i = 0; i < sources.size(); ++i)
	{
		answer.push_back(visited[sources[i]]);
	}

	return answer;
}

int main()
{
	vector<int> result = solution(5, { {1,2},{1,4},{2,4},{2,5},{4,5} }, { 1,3,5 }, 5);

	for (int i = 0; i < result.size(); ++i)
	{
		cout << "result" << i << ": " << result[i] << endl;
	}

	return 0;
}