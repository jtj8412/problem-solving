//---------------------------------------------------------------------------------- 
// [ 체육복 ] https://programmers.co.kr/learn/courses/30/lessons/42862
//
// 1. 체육복이 있는 i번째 학생은 1, 없는 학생은 0인 배열 생성
// 2. 여벌이 있으면서 도난당한 학생은 reserve 배열에서 제외
// 3. 여벌이 있는 학생 기준으로 좌측 또는 우측에 도난당한 학생에게 체육복을 줌
// 4. 체육복이 있는 학생(1) 의 갯수가 정답
//---------------------------------------------------------------------------------- 

#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int arr[32], ans = 0, i;
	vector<int>::iterator iter;

	fill_n(arr, 32, 1);
	for (iter = lost.begin(); iter != lost.end(); ++iter) arr[*iter] = 0;
	for (iter = reserve.begin(); iter != reserve.end();) {
		if (arr[*iter] == 0) {
			arr[*iter] = 1;
			iter = reserve.erase(iter);
		}
		else{
			++iter;
		}
	}

	for (iter = reserve.begin(); iter != reserve.end(); ++iter) {
		if (arr[*iter - 1] == 0) arr[*iter - 1]++;
		else arr[*iter + 1]++;
	}

	for (int i = 1; i <= n; ++i) {
		if (arr[i] != 0) ans++;
	}

	return ans;
}