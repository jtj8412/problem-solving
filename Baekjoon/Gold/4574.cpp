//----------------------------------------------------------------------------------
// [ 스도미노쿠 ] https://www.acmicpc.net/problem/4574
//----------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;

const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
int horizontal[9] = {}, vertical[9] = {}, square[9] = {}, arr[9][9] = {}, cache[9][9] = {}, visited[9][9] = {};
vector<pair<int,int>> blanks;

int getMask(int x, int y) { 
    return horizontal[y] | vertical[x] | square[x / 3 + y / 3 * 3]; 
}

vector<int> getAbleNumbers (int mask) {
    vector<int> ret;
    for (int i = 1, bit = 2; i <= 9; ++i, bit <<= 1) {
        if (!(mask & bit)) ret.push_back(i);
    }
    return ret;
}

bool dfs(int n) {
    int x = blanks[n].first, y = blanks[n].second,
        no = x / 3 + y / 3 * 3, mask = getMask(x, y), 
        mask2, nx, ny, no2;
    vector<int> nums = getAbleNumbers(mask), nums2;

    if (blanks.size() == n) return true;
    if (visited[y][x]) return dfs(n + 1);

    for (int num : nums) {

        arr[y][x] = visited[y][x] = num;
        horizontal[y] |= (1 << num);
        vertical[x] |= (1 << num);
        square[no] |= (1 << num);

        for (int j = 0; j < 4; ++j) {
            nx = x + dx[j], ny = y + dy[j];

            if (nx < 0 || nx >= 9 || ny < 0 || ny >= 9 || visited[ny][nx]) continue;

            no2 = nx / 3 + ny / 3 * 3;
            mask2 = getMask(nx, ny);
            nums2 = getAbleNumbers(mask2);

            for (int num2 : nums2) {
                if (cache[num2][num] || cache[num][num2]) continue;

                arr[ny][nx] = visited[ny][nx] = num2;
                horizontal[ny] |= (1 << num2);
                vertical[nx] |= (1 << num2);
                square[no2] |= (1 << num2);

                cache[num][num2] = cache[num2][num] = 1;

                if (dfs(n + 1)) return true;

                arr[ny][nx] = visited[ny][nx] = 0;
                horizontal[ny] &= ~(1 << num2);
                vertical[nx] &= ~(1 << num2);
                square[no2] &= ~(1 << num2);
                
                cache[num][num2] = cache[num2][num] = 0;
            }
        }

        arr[y][x] = visited[y][x] = 0;
        horizontal[y] &= ~(1 << num);
        vertical[x] &= ~(1 << num);
        square[no] &= ~(1 << num);
    }

    return false;
}

int main() {
    int i, j, no, n = -1, x1, y1, x2, y2, val1, val2, tc;
    string s;

    cin >> n; cin.ignore();
    for (tc = 1; n != 0; ++tc) {
        for (i = 0; i < n; ++i) {
            getline(cin, s);

            y1 = s[2] - 'A'; x1 = s[3] - '1'; val1 = s[0] - '0';
            y2 = s[7] - 'A'; x2 = s[8] - '1'; val2 = s[5] - '0';

            cache[val1][val2] = cache[val2][val1] = visited[y1][x1] = visited[y2][x2] = 1;

            arr[y1][x1] = val1;
            arr[y2][x2] = val2;

            horizontal[y1] |= (1 << val1);
            vertical[x1] |= (1 << val1);
            square[(x1 / 3) + (y1 / 3) * 3] |= (1 << val1);

            horizontal[y2] |= (1 << val2);
            vertical[x2] |= (1 << val2);
            square[(x2 / 3) + (y2 / 3) * 3] |= (1 << val2);
        }

        getline(cin, s);
        for (i = 0, j = 1; i < s.size(); i += 3, ++j) {
            y1 = s[i] - 'A'; x1 = s[i+1] - '1';
            arr[y1][x1] = j;
            visited[y1][x1] = 1;
            horizontal[y1] |= (1 << j);
            vertical[x1] |= (1 << j);
            square[(x1 / 3) + (y1 / 3) * 3] |= (1 << j);
        }

        for (i = 0; i < 9; ++i) for (j = 0; j < 9; ++j) {
            if (!arr[i][j]) blanks.push_back(make_pair(j, i));
        }

        dfs(0);

        printf("Puzzle %d\n", tc);
        for (i = 0; i < 9; ++i) {
            for (j = 0; j < 9; ++j)
                printf("%d", arr[i][j]);
            printf("\n");
        }

        cin >> n; cin.ignore();

        memset((int*)arr, 0, sizeof(int) * 81);
        memset((int*)visited, 0, sizeof(int) * 81);
        memset((int*)cache, 0, sizeof(int) * 81);
        memset(horizontal, 0, sizeof(int) * 9);
        memset(vertical, 0, sizeof(int) * 9);
        memset(square, 0, sizeof(int) * 9);
        blanks.clear();
    }
}