/* 방문 길이 */

#include <string>
#include <vector>
#include <unordered_map>
#define ARR_MAX 11
using namespace std;

int solution(string dirs) {
    int answer = 0, x = 5, y = 5, val, 
        visited_x[ARR_MAX][1 << ARR_MAX] = {}, visited_y[ARR_MAX][1 << ARR_MAX] = {};
    const unordered_map<char, vector<int>> DIR = {{'U', {0,-1}}, {'D', {0,1}}, {'L', {-1,0}}, {'R', {1,0}}};

    for (auto dir : dirs) {
        if (val = DIR.find(dir)->second[0]) {
            if (x + val < 0 || x + val >= ARR_MAX) continue;
            if (!visited_x[y][(1 << x) | (1 << (x + val))]) {
                visited_x[y][(1 << x) | (1 << x + val)] = 1;
                ++answer;
            }
            x += val;
        } else {
            val = DIR.find(dir)->second[1];
            if (y + val < 0 || y + val >= ARR_MAX) continue;
            if (!visited_y[x][(1 << y) | (1 << (y + val))]) {
                visited_y[x][(1 << y) | (1 << (y + val))] = 1;
                ++answer;
            }
            y += val;
        }
    }
    return answer;
}