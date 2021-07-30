/* 거리두기 확인하기 */

#include <string>
#include <vector>
#define ARR_SIZE 5
using namespace std;

bool check(vector<string> &arr, int x, int y) {
    if (x + 1 < ARR_SIZE) if(arr[y][x + 1] == 'P') return false;
    if (y + 1 < ARR_SIZE) if(arr[y + 1][x] == 'P') return false;
    if (x + 1 < ARR_SIZE && y + 1 < ARR_SIZE) if (arr[y + 1][x + 1] == 'P' && (arr[y + 1][x] != 'X' || arr[y][x + 1] != 'X')) return false;
    if (x + 1 < ARR_SIZE && y - 1 >= 0) if (arr[y - 1][x + 1] == 'P' && (arr[y - 1][x] != 'X' || arr[y][x + 1] != 'X')) return false;
    if (x + 2 < ARR_SIZE) if(arr[y][x + 2] == 'P' && arr[y][x + 1] != 'X') return false;
    if (y + 2 < ARR_SIZE) if(arr[y + 2][x] == 'P' && arr[y + 1][x] != 'X') return false;
    return true;
}

bool logic(vector<string> &arr) {
    int i, j;
    for (i = 0; i < ARR_SIZE; ++i) {
        for (j = 0; j < ARR_SIZE; ++j) {
            if (arr[i][j] == 'P' && !check(arr, j, i)) return false;
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (auto arr : places) answer.push_back(logic(arr));
    return answer;
}