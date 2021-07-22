/* 삼각 달팽이 */

#include <string>
#include <vector>

using namespace std;

#define ARR_MAX 1000

const int DIR[][2] = {{0,1}, {1,0}, {-1, -1}};
const int DIR_SIZE = 3;

int arr[ARR_MAX + 1][ARR_MAX + 1] = {};

vector<int> solution(int n) {
    vector<int> answer;
    int dir = 0, i = 0, j = 0, cnt = 0;
    
    if (n == 1) return vector<int>({1});

    while (!arr[i][j]) {
        arr[i][j] = ++cnt;
        i += DIR[dir][1];
        j += DIR[dir][0];

        if (arr[i][j] || i >= n || j >= n) {
            i -= DIR[dir][1];
            j -= DIR[dir][0];

            if (++dir >= DIR_SIZE) 
                dir = 0;
                
            i += DIR[dir][1];
            j += DIR[dir][0];    
        }
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < i + 1; ++j) {
            answer.push_back(arr[i][j]);
        }
    }

    return answer;
}