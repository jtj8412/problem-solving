/* 
[ 단속카메라 ] 

- 나의 해설
1. routes를 진입지점(routes[i][0]) 기준 오름차순 정렬
2. routes를 탐색
 2-1. 현재차량이, 카메라를 지나치지 않은 이전 차량들중 가장 빠르게 나가는 지점(pop_min)보다 늦게 진입하는 경우
  2-1-1. 이전차량들의 경로에 감시카메라 1개 설치 (++answer)
  2-1-2. 가장 빠르게 나가는 지점 갱신 (pop_min)
 2-2. 가장 빠르게 나갈 예정인 지점(pop_min) 갱신
3. 처리되지 않은 나머지 차량경로에 감시카메라 1개 설치 (answer + 1)
*/

#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0, pop_min = 30001, i;
    sort(routes.begin(), routes.end(), [](const vector<int> &a, const vector<int> &b)->bool {return (a[0] == b[0]) ? a[1] < b[1] : a[0] < b[0];});
    for (i = 0; i < routes.size(); ++i) {
        if (routes[i][0] > pop_min) { ++answer; pop_min = routes[i][1];}
        else if (pop_min > routes[i][1]) pop_min = routes[i][1];
    }
    return answer + 1;
}