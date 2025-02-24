#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define ANSWER_REMAINDER 10007

enum ETileType {
	TILE_NONE = 0,
	TILE_LEFT,
	TILE_TOP,
	TILE_RIGHT,
	TILE_MAX,
};

int solution(int n, vector<int> tops) {
	int answer = 0;

	vector<vector<int>> cached; // index, ETileType
	cached.resize(tops.size());


	cached[0].resize(TILE_MAX);
	cached[0][TILE_NONE] = 1;
	cached[0][TILE_LEFT] = 1;
	cached[0][TILE_TOP] = tops[0] ? 1 : 0;
	cached[0][TILE_RIGHT] = 1;

	for (int i = 1; i < tops.size(); ++i)
	{
		int prev_total_except_right =
			(cached[i - 1][TILE_NONE] +
			cached[i - 1][TILE_LEFT] +
			cached[i - 1][TILE_TOP]) % ANSWER_REMAINDER;
		int prev_total = 
			(prev_total_except_right +
			cached[i - 1][TILE_RIGHT]) % ANSWER_REMAINDER;

		cached[i].resize(TILE_MAX);
		cached[i][TILE_NONE] = prev_total;
		cached[i][TILE_LEFT] = prev_total_except_right;
		cached[i][TILE_TOP] = tops[i] ? prev_total : 0;
		cached[i][TILE_RIGHT] = prev_total;
	}

	for (int i = 0; i < TILE_MAX; ++i)
	{
		answer += cached[tops.size() - 1][i];
	}
	answer %= ANSWER_REMAINDER;

	return answer;
}