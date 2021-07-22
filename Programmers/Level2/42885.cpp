/* 구명보트 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int people_size = people.size(),
        answer = people_size,
        i, j = people_size;

    sort(people.begin(), people.end());

    for (i = 0; i < j - 1; ++i) {
        while (i < --j && people[i] + people[j] > limit);
        if (i < j) answer--;
    }

    return answer;
}