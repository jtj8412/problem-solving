/* 게임 맵 최단거리 */

#include <vector>
#include <queue>

using namespace std;

#define MAX_MAP_SIZE 100

struct POS {
    int x, y;
    POS(int x, int y): x(x), y(y) {}
};

int DIR[][4] = {{0,1}, {-1, 0}, {0,-1}, {1,0}};


int solution(vector<vector<int>> maps) {
    int answer = 2,
        visited[MAX_MAP_SIZE][MAX_MAP_SIZE] = {},
        width, height;
    queue<POS> q;

    width = maps[0].size(),
    height = maps.size();

    visited[height - 1][width - 1] = 1;
    q.push(POS(width - 1, height - 1));
    
    while (!q.empty()) {
        int q_size = q.size();

        for (int i = 0; i < q_size; ++i) {
            POS pos = q.front(); q.pop();

            for (int j = 0; j < 4; ++j) {
                POS new_pos(pos.x + DIR[j][0], pos.y + DIR[j][1]);

                if (new_pos.x == 0 && new_pos.y == 0)
                    return answer;

                if (new_pos.x >= width || new_pos.x < 0 ||
                    new_pos.y >= height || new_pos.y < 0)
                    continue;

                if (!maps[new_pos.y][new_pos.x] || 
                    visited[new_pos.y][new_pos.x] )
                    continue;

                visited[new_pos.y][new_pos.x] = 1;

                q.push(new_pos);
            }
        }

        ++answer;
    }

    return -1;
}
