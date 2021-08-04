/* N으로 표현 */

#include <vector>
#include <algorithm>
using namespace std;

int solution(int N, int number) {
    int answer = 0, i, j, num = N;
    vector<int> cache_vec[9] = {{},{N}};

    if (N == number) return 1;
    for (i = 2; i <= 8; ++i) {
        num *= 10; num += N;
        cache_vec[i].push_back(num);
        for (j = 1; j <= (i >> 1); ++j) {
            for (auto a : cache_vec[j]) {
                for (auto b : cache_vec[i - j]) {
                    cache_vec[i].push_back(a + b);
                    cache_vec[i].push_back(a - b);
                    cache_vec[i].push_back(b - a);
                    cache_vec[i].push_back(a * b);
                    if (b != 0) cache_vec[i].push_back(a / b);
                    if (a != 0) cache_vec[i].push_back(b / a);
                }
            }
        }
        if (find(cache_vec[i].begin(), cache_vec[i].end(), number) != cache_vec[i].end()) return i;
    }
    
    return -1;
}

