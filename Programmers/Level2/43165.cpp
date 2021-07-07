/* 타겟 넘버 */

#include <vector>

using namespace std;

int logic(vector<int> &numbers, int target, int idx=0, int sum=0) {
    if (idx == numbers.size()) {
        if (sum == target) return 1;
        return 0;
    }
    return logic(numbers, target, idx + 1, sum + numbers[idx]) + logic(numbers, target, idx + 1, sum - numbers[idx]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    answer = logic(numbers, target);

    return answer;
}