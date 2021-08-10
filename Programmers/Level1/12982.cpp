//----------------------------------------------------------------------------------
// [ 예산 ] https://programmers.co.kr/learn/courses/30/lessons/12982
//
// 작은 금액부터 적재했을때 budget을 초과하지 않는 선에서의 갯수가 최대 지원 가능 부서 
//----------------------------------------------------------------------------------

#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    int sum = 0, i;

    sort(d.begin(), d.end());
    for (i = 0; i < d.size() && sum < budget; ++i) sum += d[i];
    
    return (sum <= budget) ? i : (i - 1);
}