//----------------------------------------------------------------------------------
// [ 기지국 설치 ] https://programmers.co.kr/learn/courses/30/lessons/12979
//
// 1. 기지국의 전파 범위를 나타내는 len(w * 2 + 1)을 설정
// 2. 좌측 기지국부터 탐색
//   2-1. 이전 탐색 기지국의 우측 끝(r)과 현 탐색 기지국의 좌측 끝(l) 획득
//   2-2. 현 탐색 기지국 ~ 이전 탐색 기지국 사이에 전파가 전달되지 않는 범위 획득 (r - l)
//   2-3. 전파가 전달되지 않는 범위를 기지국 전파 범위로 나눴을 때 몫이 해당 범위의 최소 설치 갯수
//   2-4. 2-3 나눗셈 결과 나머지가 있을 경우 기지국을 하나 더 설치한다
// 3. 2의 탐색 결과 기지국 설치 갯수가 정답
//----------------------------------------------------------------------------------

#include <vector>
using namespace std;

int logic(int l, int r, int len) {
    if (r - l <= 0) return 0;
    return (r - l) / len + (((r - l) % len == 0) ? 0 : 1);
}

int solution(int n, vector<int> stations, int w) {
    int len = w * 2 + 1, answer = logic(1, stations[0] - w, len), i, size = stations.size();
    for (i = 1; i < size; ++i) answer += logic(stations[i-1] + w + 1, stations[i] - w, len);
    answer += logic(stations.back() + w + 1, n + 1, len);
    return answer;
}