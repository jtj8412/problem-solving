//----------------------------------------------------------------------------------
// [ [1차] 셔틀버스 ] https://programmers.co.kr/learn/courses/30/lessons/17678
//
// 1. 크루가 대기열에 도착하는 시간의 오름차순으로 pq에 저장한다
//    편의를 위해 string 데이터를 int로 변환한다
// 2. 대기열에 먼저 도착한 크루 순으로 셔틀버스에 차례대로 탑승시킨다
//    i번째 셔틀버스일 경우 time_vec[i-1]에 크루의 대기열 도착 시간 정보를 삽입한다
// 3. 마지막 셔틀버스에서 탑승 가능한 시간을 찾는다
//   3-1. 셔틀버스에 자리가 남을 경우, 셔틀버스가 딱 도착한 시점이 가장 늦게 탑승하는 시점이다
//   3-2. 자리가 남지 않았을 경우, 해당 셔틀버스의 가장 마지막 탑승자의 대기시간-1초가 탑승 시점이다
//----------------------------------------------------------------------------------

#include <string>
#include <vector>
#include <queue>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> time_vec[10];
    priority_queue<int, vector<int>, greater<int>> pq;
    int i, size = timetable.size(), time, idx;

    for (i = 0; i < size; ++i)
        pq.push((timetable[i][0]-'0') * 600 + (timetable[i][1]-'0') * 60 + (timetable[i][3]-'0') * 10 + (timetable[i][4])-'0');
    
    for (i = 0; i < size; ++i) {
        time = pq.top(); pq.pop();
        if (time > 540) idx = (time - 541) / t + 1;
        else idx = 0;
        if (idx >= n) continue;
        while (time_vec[idx].size() == m) ++idx;
        if (idx >= n) continue;
        time_vec[idx].push_back(time);
    }

    if (time_vec[n-1].size() != m) time = 540 + t * (n - 1);
    else time = time_vec[n-1].back() - 1;

    answer += ((time / 60 > 9) ? to_string(time / 60) : "0" + to_string(time / 60)) + ":";
    answer += (time % 60 > 9) ? to_string(time % 60) : "0" + to_string(time % 60);

    return answer;
}