#include <iostream>
#include <string>
#include <vector>

#define PUZZLE_LEVEL_MAX 100000

using namespace std;

long long calculate_elapsed_time(const vector<int>& diffs, const vector<int>& times, long long level)
{
	long long ret = 0;

	long long diff, time, prev_time;
	for (int i = 0; i < diffs.size(); ++i)
	{
		diff = diffs[i];
		time = times[i];

		ret += time;

		if (diffs[i] > level)
		{
			prev_time = i > 0 ? times[i - 1] : 0;
			ret += (diff - level) * (time + prev_time);
		}
	}

	return ret;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
	int answer = PUZZLE_LEVEL_MAX;

	int search_left = 1;
	int search_right = PUZZLE_LEVEL_MAX;

	while (search_left <= search_right)
	{
		int mid = (search_left + search_right) >> 1;
		long long elapsed_time = calculate_elapsed_time(diffs, times, mid);
		if (elapsed_time <= limit)
			answer = min(answer, mid);

		if (elapsed_time > limit)
			search_left = mid + 1;
		else
			search_right = mid - 1;
	}

	return answer;
}