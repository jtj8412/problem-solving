/* 등굣길 */

#include <vector>

int solution(int m, int n, std::vector<std::vector<int>> puddles) {
    int answer = 0, cache[100][100] = {{1}}, i, j;

    for (i = 0; i < puddles.size(); ++i) cache[puddles[i][1] - 1][puddles[i][0] - 1] = -1;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            if (cache[i][j] == -1) continue;
            if (j + 1 < m && cache[i][j + 1] != -1) cache[i][j + 1] = (cache[i][j + 1] + cache[i][j]) % 1000000007;
            if (i + 1 < n && cache[i + 1][j] != -1) cache[i + 1][j] = (cache[i + 1][j] + cache[i][j]) % 1000000007;
        }
    }

    return cache[n - 1][m - 1];
}