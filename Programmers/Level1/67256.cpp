/* 키패드 누르기 */

#include <string>
#include <vector>

using namespace std;

const int num_x[12] = { 1, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 2};
const int num_y[12] = { 0, 3, 3, 3, 2, 2, 2, 1, 1, 1, 0, 0};
const int left_num[3] = { 1, 4, 7 };
const int right_num[3] = { 3, 6, 9 };

int left_cur = 10, right_cur = 11;
string answer = "";

void left(int num)
{
	left_cur = num;
	answer.push_back('L');
}

void right(int num)
{
	right_cur = num;
	answer.push_back('R');
}

bool left_check(int num)
{
	for (int i = 0; i < 3; ++i) {
		if (num == left_num[i]) {
			left(num);
			return true;
		}
	}
	return false;
}

bool right_check(int num)
{
	for (int i = 0; i < 3; ++i) {
		if (num == right_num[i]) {
			right(num);
			return true;
		}
	}
	return false;
}

void mid_check(int num, string& hand)
{
	int left_dist = abs(num_x[left_cur] - num_x[num]) + abs(num_y[left_cur] - num_y[num]);
	int right_dist = abs(num_x[right_cur] - num_x[num]) + abs(num_y[right_cur] - num_y[num]);

	if ((left_dist < right_dist) || (left_dist == right_dist && hand == "left")) left(num);
	else right(num);
}

string solution(vector<int> numbers, string hand) {

	for (int i = 0; i < numbers.size(); ++i) {
		int num = numbers[i];
		if (left_check(num));
		else if (right_check(num));
		else mid_check(num, hand);
	}

	return answer;
}