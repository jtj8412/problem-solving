/* 카카오프렌즈 컬러링북 */

#include <vector>
#include <queue>

using namespace std;

#define MAX_WIDTH 100

struct POS {
    int x, y;
    POS(int x, int y) : x(x), y(y) {}
};

const int DIR[][3] = {{1,0}, {-1,0}, {0,1}, {0, -1}};
int (*visited)[MAX_WIDTH];

vector<int> solution(int h, int w, vector<vector<int>> map) {
    vector<int> answer = {0, 0};
    queue<POS> q;

    visited = new int[h][100];
    fill_n((int*)visited, h * 100, 0);

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!map[i][j] || visited[i][j]) continue;
            
            int cnt = 1;
    
            q.push(POS(j, i));
            visited[i][j] = 1;
            while (!q.empty()) {
                POS pos = q.front(); q.pop();

                for (int k = 0; k < 4; ++k) {
                    POS new_pos(pos.x + DIR[k][0], pos.y + DIR[k][1]);
                    
                    if (new_pos.x < 0 || new_pos.x >= w ||
                        new_pos.y < 0 || new_pos.y >= h)
                        continue;
                    
                    if (map[new_pos.y][new_pos.x] != map[i][j] ||
                        visited[new_pos.y][new_pos.x])
                        continue;

                    q.push(new_pos);

                    visited[new_pos.y][new_pos.x] = 1;

                    ++cnt;
                }
            }

            ++answer[0];
            answer[1] = max(answer[1], cnt);
        }
    }

    delete[] visited;

    return answer;
}