//----------------------------------------------------------------------------------
// [ 징검다리 건너기 ] https://programmers.co.kr/learn/courses/30/lessons/64062
//
// 1. 앞에서부터 k개씩 priority_queue에 내림차순으로 담는다
// 2. priority_queue 상단에 있는 가장 큰 데이터(top)가 i ~ i+k 범위를 벗어날 경우 해당 데이터를 삭제한다
// 3. 1,2번을 반복하면서 priority_queue에 있는 가장 큰 데이터가 가장 작은 경우가 정답이다
//----------------------------------------------------------------------------------

#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct DATA { 
    int stone, idx;
    DATA() {}
    DATA(int stone, int idx) : stone(stone), idx(idx) {}
    bool operator()(const DATA &a, const DATA &b) { return a.stone < b.stone; }
};

int solution(vector<int> stones, int k) {
    int answer, i, size = stones.size();
    priority_queue<DATA, vector<DATA>, DATA> pq;

    if (k == 1) return *min_element(stones.begin(), stones.end());

    for (i = 0; i < k; ++i)
        pq.push(DATA(stones[i], i));
    answer = pq.top().stone;

    for (i = 0; i < size - k; ++i) {
        while (pq.top().idx <= i) pq.pop();
        pq.push(DATA(stones[i+k], i+k));
        if (answer > pq.top().stone) answer = pq.top().stone;
    }

    return answer;
}