//----------------------------------------------------------------------------------
// [ 없는 숫자 더하기 ] https://programmers.co.kr/learn/courses/30/lessons/86051
//----------------------------------------------------------------------------------

#include <vector>
using namespace std;

int solution(vector<int> numbers) {
    int answer = 45;
    for (auto i : numbers) answer -= i;
    return answer;
}
