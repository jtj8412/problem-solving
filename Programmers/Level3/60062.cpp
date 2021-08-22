//----------------------------------------------------------------------------------
// [ 외벽 점검 ] https://programmers.co.kr/learn/courses/30/lessons/60062
//----------------------------------------------------------------------------------

#include <algorithm>
#include <vector>
using namespace std;

int solution(int n, vector<int> weak_vec, vector<int> dist_vec) {
    vector<int> vec_arr[9] = {{0}};
    int a, b, c, d, e, flag, end, cache[1 << 15] = {}, 
        dist_vec_size = dist_vec.size(), weak_vec_size = weak_vec.size(),
        flag_max = 1 << weak_vec_size, all = flag_max - 1;

    sort(dist_vec.begin(), dist_vec.end(), greater<int>());

    for (a = 0; a < dist_vec_size; ++a) {
        for (b = 0; b < vec_arr[a].size(); ++b) {
            for (d = 0, c = 1; c < flag_max; c <<= 1, ++d) {
                if (vec_arr[a][b] & c) continue;
                flag = vec_arr[a][b];
                end = weak_vec[d] + dist_vec[a];
                for (e = d; e < weak_vec_size && weak_vec[e] <= end; ++e) flag |= (1 << e);
                if (end >= n) {
                    end %= n;
                    for (e = 0; weak_vec[e] <= end; ++e) flag |= (1 << e);
                }
                if (cache[flag]) continue;
                if (flag == all) return a + 1;
                cache[flag] = 1;
                vec_arr[a+1].push_back(flag);
            }
        }
    }

    return -1;
}