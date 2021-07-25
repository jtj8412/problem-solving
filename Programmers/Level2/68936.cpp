/* 쿼드압축 후 개수 세기 */

#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer = {0, 0};
    int arr_size = arr.size(), size = 1, dist, area, i, j;

    for (i = 0; i < arr_size; ++i) {
        for (j = 0; j < arr_size; ++j) {
            ++answer[arr[i][j]];
            if (arr[i][j] == 0) arr[i][j] = -1;
        }
    }

    while ((size <<= 1) <= arr_size) {
        dist = (size >> 1);
        area = size * size;
        for (i = 0; i < arr_size; i += size) {
            for (j = 0; j < arr_size; j += size) {
                arr[i][j] += arr[i + dist][j] + arr[i][j + dist] + arr[i + dist][j + dist];
                if (arr[i][j] == -area) answer[0] -= 3;
                else if (arr[i][j] == area) answer[1] -= 3;
            }
        }
    }
    
    return answer;
}