//----------------------------------------------------------------------------------
// [ [1차] 추석 트래픽 ] https://programmers.co.kr/learn/courses/30/lessons/17676
//
// 1. 시작시간(l) ~ 종료시간(r) 데이터를 lines_vec에 저장
// 2. lines_vec을 시직시간(l)의 오름차순으로 정렬
// 3. lines_vec에서 시작시간 순으로 데이터를 꺼내어 priority_queue에 삽입
//   3-1. priority_queue 내에서 종료시간(r) 오름차순으로 정렬
//   3-2. 삽입하려는 데이터의 시작시간보다, 이전에 priority_queue에 삽입했던 종료시간이 더
//        빠른 데이터들을 삭제
// 4. 3번 과정 중 priority_queue의 데이터 갯수가 가장 많을 때의 갯수가 정답
//----------------------------------------------------------------------------------

#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct DATA { 
    int l, r;
    bool operator()(const DATA &a, const DATA &b) { return a.r > b.r; }
};

int solution(vector<string> lines) {
    int answer = 1, i, j, l, r;
    vector<DATA> lines_vec;
    priority_queue<DATA, vector<DATA>, DATA> pq;

    for (i = 0; i < lines.size(); ++i) {
        r = (lines[i][11]-'0')*36000000 + (lines[i][12]-'0')*3600000 + (lines[i][14]-'0')*600000 + (lines[i][15]-'0')*60000 + 
            (lines[i][17]-'0')*10000 + (lines[i][18]-'0')*1000 + (lines[i][20]-'0')*100 + (lines[i][21]-'0')*10 + (lines[i][22]-'0');
        l = r - stod(lines[i].substr(24, lines[i].size() - 25)) * 1000 + 1;
        lines_vec.push_back(DATA({l, r}));
    }

    sort(lines_vec.begin(), lines_vec.end(), [](const DATA &a, const DATA &b)->bool{ return a.l < b.l; });

    for (int i = 0; i < lines_vec.size(); ++i) {
        r = lines_vec[i].l - 1000;
        while (!pq.empty() && pq.top().r <= r) pq.pop();
        pq.push(lines_vec[i]);
        if (answer < pq.size()) answer = pq.size();
    }

    return answer;
}