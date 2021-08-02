/* 여행경로 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    return answer;
}

int main() {
    vector<vector<string>> vvec = {{"ICN", "JFK"},{"HND", "IAD"},{"JFK", "HND"}};
    for (auto s : solution(vvec)) {
        cout << s << " " << endl;
    }
}