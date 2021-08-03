/* 정수 삼각형 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int cache[501][501] = {{triangle[0][0]}}, i, j, size = triangle.size();

    for (i = 0; i < size - 1; ++i) {
        for (j = 0; j < i + 1; ++j) {
            cache[i + 1][j] = max(cache[i][j] + triangle[i + 1][j], cache[i + 1][j]);
            cache[i + 1][j + 1] = cache[i][j] + triangle[i + 1][j + 1];
        }
    }

    for (i = 0; i < size; ++i) {
        for (j = 0; j < i + 1; ++j) {
            cout << cache[i][j] << " ";
        }
        cout << endl;
    }

    return *max_element(cache[size - 1], cache[size - 1] + size);
}

int main() {
    vector<vector<int>> vvec = {{7},{3, 8},{8, 1, 0},{2, 7, 4, 4},{4, 5, 2, 6, 5}};
    cout << solution(vvec) << endl;
}
