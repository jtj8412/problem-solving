//----------------------------------------------------------------------------------
// [ 스도쿠 ] https://www.acmicpc.net/problem/2580
//----------------------------------------------------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int horizontal[9] = {}, vertical[9] = {}, square[9] = {}, arr[9][9];
vector<pair<int,int>> blanks;

bool dfs(int n) {
    int no = blanks[n].first / 3 + blanks[n].second / 3 * 3,
        mask = horizontal[blanks[n].second] | vertical[blanks[n].first] | square[no];

    if (blanks.size() == n) return true;

    for (int i = 1, bit = 2; i <= 9; ++i, bit <<= 1) {
        if (mask & bit) continue;

        arr[blanks[n].second][blanks[n].first] = i;
        horizontal[blanks[n].second] |= (1 << i);
        vertical[blanks[n].first] |= (1 << i);
        square[no] |= (1 << i);

        if (dfs(n + 1)) return true;

        arr[blanks[n].second][blanks[n].first] = 0;
        horizontal[blanks[n].second] &= ~(1 << i);
        vertical[blanks[n].first] &= ~(1 << i);
        square[no] &= ~(1 << i);
    }

    return false;
}

int main() {
    int i, j, no, mask, bit, num;

    for (i = 0; i < 9; ++i) for (j = 0; j < 9; ++j) {
        scanf("%d", &arr[i][j]);
        if (arr[i][j] == 0) blanks.push_back(make_pair(j,i));
        horizontal[i] |= (1 << arr[i][j]);
        vertical[j] |= (1 << arr[i][j]);
        square[(j / 3) + (i / 3) * 3] |= (1 << arr[i][j]);
    }

    dfs(0);

    for (i = 0; i < 9; ++i) {
        for (j = 0; j < 9; ++j)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}