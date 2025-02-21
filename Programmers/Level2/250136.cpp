#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>
#include <stack>
#include <map>

using namespace std;

vector<vector<int>> Delta = {
    { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 }
};

map<int, int> CountById;
vector<set<int>> ColumnIds;
vector<vector<int>> Visited;
int RowLen, ColumnLen;

void travle(const vector<vector<int>>& land, int col, int row, int id)
{
    queue<pair<int, int>> q;

    q.push(make_pair(col, row));

    while (!q.empty())
    {
        pair<int, int> pos = q.front();
        q.pop();

        ColumnIds[pos.first].insert(id);
        CountById[id]++;

        for (int i = 0; i < Delta.size(); ++i)
        {
            int dx = pos.first + Delta[i][0];
            int dy = pos.second + Delta[i][1];

            if (dx < 0 || dx >= ColumnLen || dy < 0 || dy >= RowLen)
                continue;

            if (!land[dy][dx])
                continue;

            if (Visited[dy][dx])
                continue;
            Visited[dy][dx] = true;

            q.push(make_pair(dx, dy));
        }
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;

    RowLen = land.size();
    ColumnLen = land[0].size();

    ColumnIds.resize(ColumnLen);
    Visited.resize(RowLen);
    for (int i = 0; i < RowLen; ++i)
        Visited[i].resize(ColumnLen);

    for (int i = 0; i < RowLen; ++i)
    {
        for (int j = 0; j < ColumnLen; ++j)
        {
            if (Visited[i][j])
                continue;
            Visited[i][j] = true;

            if (land[i][j])
                travle(land, j, i, i * ColumnLen + j);
        }
    }

    for (int i = 0; i < ColumnLen; ++i)
    {
        int count = 0;

        for (auto iter = ColumnIds[i].begin(); iter != ColumnIds[i].end(); ++iter)
        {
            count += CountById[*iter];
        }

        if (count > answer)
        {
            answer = count;
        }
    }

    return answer;
}