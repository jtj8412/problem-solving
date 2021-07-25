/* 2개 이하로 다른 비트 */

#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    int size = numbers.size(), i;
    long long bit;

    for (i = 0; i < size; ++i) {
        for (bit = 1; bit & numbers[i]; bit <<= 1);
        answer.push_back(numbers[i] + bit - (bit >> 1));
    }
    
    return answer;
}