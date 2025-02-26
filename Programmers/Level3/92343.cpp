#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> nodes;
vector<int> cached; // visited: sheep

int get_movable(int node_idx)
{
	int movable = 0;
	for (int i = 0; i < nodes[node_idx].size(); ++i)
		movable |= (1 << nodes[node_idx][i]);
	return movable;
}

int travle(const vector<int>& info, int sheep, int wolf, int movable, int visited)
{
	int max_sheep = sheep;

	if (sheep < cached[visited])
		return sheep;

	for (int i = 1; i < info.size(); ++i)
	{
		int bit = 1 << i;

		if (!(movable & bit))
			continue;

		if (visited & bit)
			continue;

		int next_sheep = sheep + (info[i] ? 0 : 1);
		int next_wolf = wolf + (info[i] ? 1 : 0);
		int next_visited = visited | bit;

		if (next_sheep <= next_wolf)
			continue;

		if (cached[next_visited] && next_sheep < cached[next_visited])
			continue;

		int result = travle(info, next_sheep, next_wolf, movable | get_movable(i), next_visited);
		if (result > max_sheep)
			max_sheep = result;
	}

	return max_sheep;
}

int solution(vector<int> info, vector<vector<int>> edges) {
	// init nodes
	nodes.resize(info.size());
	for (int i = 0; i < edges.size(); ++i)
		nodes[edges[i][0]].push_back(edges[i][1]);

	// init cached
	cached.resize(1 << info.size());
	
	// travle
	return travle(info, 1, 0, get_movable(0), 1);
}