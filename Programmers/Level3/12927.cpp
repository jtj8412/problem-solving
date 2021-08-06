/* 
[ 야근 지수 ]

- 나의 해설
1. works 내림차순 정렬
2. 작업량이 부족할때까지 아래 행동을 반복
 2-1. 다음 최댓값을 찾는다, (works[i]: 이전 최댓값, works[i+1]: 다음 최댓값)
 2-2. works[0] ... works[i] 는 같은 값인 것으로 '간주'
 2-3. works[0] ... works[i] 를 works[i+1] 로 감소하는데 필요한 일량 -> (works[i] - works[i+1]) * (i + 1)
 2-4. 남은 일량에 2-3 값을 감산, 일량이 부족할 경우 반복 해제
3. 남은 일량과, 같은 값으로 간주되는 works[0] ... works[i] 를 통해 0부터 i까지의 야근 지수 계산
4. i+1 부터 마지막까지의 야근 지수 계산
*/

#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int i, val, j;
    sort(works.begin(), works.end(), [](int a, int b)->bool{return a > b;});
    for (i = 0; i < works.size() - 1; ++i) {
        if (works[i] == works[i + 1]) continue;
        if ((val = (works[i] - works[i + 1]) * (i + 1)) > n) break;
        n -= val;
    }
    answer += (long long)pow(max(works[i] - (n / (i + 1)), 0), 2) * (i + 1 - (n % (i + 1))) + pow(max(works[i] - (n / (i + 1)) - 1, 0), 2) * (n % (i + 1));
    for (j = i + 1; j < works.size(); ++j) answer += works[j] * works[j];
    return answer;
}