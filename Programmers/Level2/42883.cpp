/* 큰 수 만들기 */

#include <string>
#include <queue>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    queue<int> pos_q[10];
    int num_size = number.size();
    int sel_cnt = num_size - k;
    int cur = -1;

    for (int i = 0; i < num_size; ++i) {
        pos_q[number[i] - '0'].push(i);
    }

    for (int i = 0; i < sel_cnt; ++i) {
        for (int j = 9; j >= 0; --j) {
            int front;
            if (pos_q[j].size() == 0)
                continue;
            while ((front = pos_q[j].front()) < cur) 
                pos_q[j].pop();
            if (front <= num_size - sel_cnt + i) {
                cur = front + 1;
                pos_q[j].pop();
                answer += j + '0';
                break;
            }
        }
    }
    return answer;
}