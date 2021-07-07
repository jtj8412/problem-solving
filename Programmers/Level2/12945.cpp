/* 피보나치 수 */

#define NUM_MAX 100000

using namespace std;

int cache[NUM_MAX + 1] = {0, 1, 1};

int solution(int n) {
    cache[0] = 0;
    cache[1] = cache[2] = 1;

    for (int i = 3; i <= n; ++i) {
        cache[i] = (cache[i - 1] + cache[i - 2]) % 1234567;
    }

    return cache[n];
}