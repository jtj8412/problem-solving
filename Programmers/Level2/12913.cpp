/* 땅따먹기 */

#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }
int max(int a, int b, int c) { return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c); }

int solution(vector<vector<int>> land) {
    int cache[4] = {}, tmp[4];

    for (auto col : land) {
        tmp[0] = col[0] + max(cache[1], cache[2], cache[3]);
        tmp[1] = col[1] + max(cache[0], cache[2], cache[3]);
        tmp[2] = col[2] + max(cache[0], cache[1], cache[3]);
        tmp[3] = col[3] + max(cache[0], cache[1], cache[2]);
        memcpy(cache, tmp, 16);
    }
    
    return max(cache[0], max(cache[1], cache[2], cache[3]));
}