//----------------------------------------------------------------------------------
// [ 외벽 점검 ] https://programmers.co.kr/learn/courses/30/lessons/60062
//
// 1. 친구의 이동 거리(dist_vec)를 내림차순으로 정렬
// 2. bfs 방식으로 가장 큰 이동 거리(dist_vec)을 가진 친구부터 차례대로 삽입하여 만들 수 있는 경우 추출
//   2-1. 만들어 지는 경우, 즉 a명의 친구로 방문할 수 있는 취약 지점의 리스트는 비트 마스크로 표현 (vec_arr[a])
//   2-2. 이전에 방문했던 탐색 지점과, 새로운 친구의 탐색 시작 지점이 같을 경우 무시 (vec_arr[a][b] & c)
//   2-3. 방문 지점 조합이 이전에 있었던 조합일 경우 무시 (cache[flag])
//   2-4. flag가 모든 취약 지점을 방문했다고 나타낼때 현 시점 투입된 친구 수가 정답
// 3. 2번 과정으로 정답이 나오지 않을 경우 전부 점검할 수 없는 경우로 -1 정답
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