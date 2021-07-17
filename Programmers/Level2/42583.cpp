#include <string>
#include <vector>
#include <queue>

using namespace std;

struct DATA {
    int w, t;
    DATA(int w, int t) : w(w), t(t) {}
};

int solution(int bridge, int limit, vector<int> weight_vec) {
    int last_t = bridge,
        cur_t = 1,
        cur_w = weight_vec[0],
        w_size = weight_vec.size();
    queue<DATA> q;

    q.push(DATA(weight_vec[0], bridge));

    for (int i = 1; i < weight_vec.size(); ++i) {
        int time = last_t + 1;

        while (cur_t > q.front().t) {
            cur_w -= q.front().w;
            q.pop();
        }

        while (cur_w + weight_vec[i] > limit) {
            cur_w -= q.front().w;
            cur_t = q.front().t;
            time = q.front().t + bridge;
            q.pop();
        }
        
        q.push(DATA(weight_vec[i], time));

        cur_w += weight_vec[i];
        last_t = time;
        cur_t++;
    }

    return last_t + 1;
}