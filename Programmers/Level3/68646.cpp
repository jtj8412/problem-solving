//----------------------------------------------------------------------------------
// [ 풍선 터트리기 ] https://programmers.co.kr/learn/courses/30/lessons/68646
//
// 어느 일정 범위를 기준으로 풍선을 터뜨렸을 때 무조건 하나의 풍선만 남는다는 것을 이용한다
// 현재 탐색중인 풍선이 끝까지 남는다는 것을 판단하기 위해서는 탐색중인 풍선 기준으로 좌측
// 풍선들의 최솟값, 우측 풍선들의 최솟값과 비교했을 때 가장 최솟값에 위치하거나, 그 다음
// 최솟값에 위치하면 '번호가 더 작은 풍선'을 터트릴 수 있는 기회를 사용하여 끝까지 남을 수 있다
// 우측 최솟값을 판단하기 위해 priority_queue를 사용한다
//----------------------------------------------------------------------------------

#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> a) {
    int answer = 2, i, a_size = a.size(), lmin = 0x7fffffff, arr[3];
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> rpq; // <val, idx>

    if (a.size() < 3) return a.size();

    for (i = 1; i < a_size; ++i)
        rpq.push(make_pair(a[i], i));

    for (i = 1; i < a_size - 1; ++i) {
        while (rpq.top().second <= i) rpq.pop();
        if (lmin > a[i-1]) lmin = a[i-1];
        rpq.push(make_pair(a[i+1], i+1));
        arr[0] = lmin; arr[1] = a[i]; arr[2] = rpq.top().first;
        sort(arr, arr+3);
        if (a[i] == arr[0] || a[i] == arr[1]) ++answer;
    }

    return answer;
}