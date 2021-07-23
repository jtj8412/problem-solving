/* 행렬 테두리 회전하기 */

#include <vector>

#define MIN(a, b) (a > b ? b : a)

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int arr[100][100] = {},
        queries_size = queries.size(),
        i, j, x, y, *p_prev, min, tmp;

    for (i = 0; i < rows; ++i) {
        for (j = 0; j < columns; ++j)
            arr[i][j] = i * columns + j + 1;
    }

    for (i = 0; i < queries_size; ++i) {
        y = queries[i][0]; x = queries[i][1] - 1;
        p_prev = &arr[y - 1][x];
        tmp = arr[y - 1][x];
        min = *p_prev;

        while (y != queries[i][0] - 1 || x != queries[i][1] - 1) {
            *p_prev = arr[y][x];
            min = MIN(min, arr[y][x]);
            p_prev = &arr[y][x];

            if (y == queries[i][0] - 1) --x;
            else if (x == queries[i][3] - 1) --y;
            else if (y == queries[i][2] - 1) ++x;
            else ++y;
        }
        *p_prev = tmp;
        answer.push_back(min);
    }
    return answer;
}