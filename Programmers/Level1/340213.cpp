#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define VIDEO_JUMP_SEC 10

int TimeToSeconds(const string& time)
{
	return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

string SecondsToTime(int seconds)
{
	string time = "00:00";

	int m = seconds / 60;
	int s = seconds % 60;

	string min_str = to_string(m);
	if (min_str.size() == 1)
	{
		time[1] = min_str[0];
	}
	else
	{
		time[0] = min_str[0];
		time[1] = min_str[1];
	}

	string sec_str = to_string(s);
	if (sec_str.size() == 1)
	{
		time[4] = sec_str[0];
	}
	else
	{
		time[3] = sec_str[0];
		time[4] = sec_str[1];
	}

	return time;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
	int cur_sec = TimeToSeconds(pos);
	int video_len_sec = TimeToSeconds(video_len);
	int op_start_sec = TimeToSeconds(op_start);
	int op_end_sec = TimeToSeconds(op_end);

	if (cur_sec >= op_start_sec && cur_sec < op_end_sec)
		cur_sec = op_end_sec;

	for (int i = 0; i < commands.size(); ++i)
	{
		if (commands[i][0] == 'n') // next
		{
			cur_sec = min(video_len_sec, cur_sec + VIDEO_JUMP_SEC);
		}
		else // prev
		{
			cur_sec = max(0, cur_sec - VIDEO_JUMP_SEC);
		}

		if (cur_sec >= op_start_sec && cur_sec < op_end_sec)
			cur_sec = op_end_sec;
	}

	return SecondsToTime(cur_sec);
}
