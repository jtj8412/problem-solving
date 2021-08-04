/* 2 x n 타일링 */

int solution(int n) {
    int cache[3] = {0, 1, 2}, i;
    if (n < 3) return cache[n];
    for (i = 3; i <= n; ++i) {
        cache[0] = cache[1];
        cache[1] = cache[2];
        cache[2] = cache[0] + cache[1];
    }
    return cache[2];
}