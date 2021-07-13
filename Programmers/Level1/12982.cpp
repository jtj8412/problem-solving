/* 예산 */

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0, sum = 0, i;

    sort(d.begin(), d.end());

    for (i = 0; i < d.size(); ++i) {
        sum += d[i];
        if (sum >= budget) break;    
    }
    
    if (sum == budget) answer = i + 1;
    else answer = i;

    return answer;
}