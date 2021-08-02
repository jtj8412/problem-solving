/* 디스크 컨트롤러 */

#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct COMPARE {
    bool operator()(vector<int> &a, vector<int> &b) { return a[1] > b[1];}
};


int solution(vector<vector<int>> jobs) {
    int answer = 0, time = 0;
    priority_queue<vector<int>, vector<vector<int>>, COMPARE> pq;

    sort(jobs.begin(), jobs.end(), [](vector<int> &a, vector<int> &b)->bool{return a[0] < b[0];});

    for (auto job : jobs) {
        if (job[0] <= time) {
            pq.push(job);
            continue;
        }
        while (job[0] > time && !pq.empty()) {
            answer += (pq.top()[1] + time) - pq.top()[0];
            time += pq.top()[1]; pq.pop();
        }
        if (pq.empty() && time < job[0]) time = job[0];
        pq.push(job);
    }
    while (!pq.empty()) {
        answer += (pq.top()[1] + time) - pq.top()[0];
        time += pq.top()[1]; pq.pop();
    }

    return answer / jobs.size();
}