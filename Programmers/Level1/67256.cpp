//----------------------------------------------------------------------------------
// [ 키패드 누르기 ] https://programmers.co.kr/learn/courses/30/lessons/67256
//
// 1. 숫자별 x,y 좌표 정의 (num_x, num_y)
// 2. 숫자별 방향 문자 정의 (hand_alpha)
// 3. numbers에서 누르려는 숫자를 하나씩 뽑고 방향 문자(hand_alpha)를 추출
// 4-1. 3에서 추출한게 'L' 또는 'R'일 경우 방향에 맞게 left 또는 right 갱신
// 4-2. 3에서 추출한게 ' '일 경우, 가까운 손 또는 익숙한 손으로 이동 후 left right 갱신
// 5. 4의 결과를 모은 것이 정답
//----------------------------------------------------------------------------------


#include <string>
#include <vector>
using namespace std;

const int num_x[12] = { 1, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 2}, 
	num_y[12] = { 0, 3, 3, 3, 2, 2, 2, 1, 1, 1, 0, 0};

int dist(int num1, int num2) { return abs(num_x[num1] - num_x[num2]) + abs(num_y[num1] - num_y[num2]); }

string solution(vector<int> numbers, string hand) {
	string answer = "", hand_alpha = " L RL RL R";
	int left = 10, right = 11, rem, ldist, rdist;

	for (auto num : numbers) {
		if (hand_alpha[num] == ' ') {
			ldist = dist(left, num); rdist = dist(right, num);
			if (ldist < rdist || (ldist == rdist && hand[0] == 'l')) {
				left = num;
				answer += 'L';
			} else {
                right = num;
				answer += 'R';
			}
		} else {
			answer += hand_alpha[num];
			if (hand_alpha[num] == 'L') left = num;
			else right = num;
		}
	}
	
	return answer;
}