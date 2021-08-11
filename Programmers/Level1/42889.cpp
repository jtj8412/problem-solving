//----------------------------------------------------------------------------------
// [ 실패율 ] https://programmers.co.kr/learn/courses/30/lessons/42889
//
// 1. 해당 스테이지에 도달한 사용자 수를 기록한 배열(arr) 생성
// 2. N+1 ~ 1 까지 도달한 사용자(clear) 누적
// 3. 실패율 및 스테이지를 저장(cache)
// 4. 실패율 내림차순, 스테이지 오름차순으로 cache 정렬
// 5. 정렬된 스테이지의 순서가 정답
//----------------------------------------------------------------------------------

#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer(N);
	vector<pair<int, float>> cache;
	int arr[502] = {}, clear, i;
	
	for (auto i : stages) ++arr[i];

	clear = arr[N + 1];

	for (i = N; i >= 1; --i) {
		clear += arr[i];
		if (!clear) cache.push_back(make_pair(i, 0));
		else cache.push_back(make_pair(i, (float)arr[i] / clear));
	}

	sort(cache.begin(), cache.end(), [](const pair<int, float> &a, const pair<int, float> &b)->bool
		{return (a.second == b.second) ? a.first < b.first : a.second > b.second;});

	for (i = 0; i < N; ++i) answer[i] = cache[i].first;

	return answer;
}