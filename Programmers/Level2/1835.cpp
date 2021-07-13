/* 단체사진 찍기 */

#include <string>
#include <vector>
#include <numeric>

using namespace std;

#define IS_EQUAL(n) (n & 0x0100)
#define IS_GREATER(n) (n & 0x0200)
#define IS_LESS(n) (n & 0x0400)
#define GET_DEST(n) (n & 0x000f)
#define GET_VALUE(n) ((n & 0x00f0) >> 4)
#define FRIENDS_COUNT 8

const char FRIENDS_WORD[] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
const char OPERATION[] = {'=', '>', '<'};

vector<int> frnd_vec(FRIENDS_COUNT);
vector<int> cond_vec[FRIENDS_COUNT];
int frnd_pos[FRIENDS_COUNT];
int answer;


int WordToInt(char word) {
    for (int i = 0; i < FRIENDS_COUNT; ++i) {
        if (FRIENDS_WORD[i] == word)
            return i;
    }
    return -1;
}

int OperationToInt(char operation) {
    int ret = 0x0100;
    for (int i = 0; i < 3; ++i, ret <<= 1) {
        if (OPERATION[i] == operation)
            return ret;
    }
    return -1;
}

void Init(vector<string> &data) {
    answer = 0;

    frnd_vec.clear();
    for (int i = 0; i < FRIENDS_COUNT; ++i)
        cond_vec[i].clear();

    iota(frnd_vec.begin(), frnd_vec.end(), 0);

    fill_n(frnd_pos, FRIENDS_COUNT, -1);

    for (int i = 0; i < data.size(); ++i) {
        int idx1 = WordToInt(data[i][0]),
            idx2 = WordToInt(data[i][2]),
            oper = OperationToInt(data[i][3]),
            val = (data[i][4] - '0') << 4;
        cond_vec[idx1].push_back(idx2 | val | oper);
        cond_vec[idx2].push_back(idx1 | val | oper);
    }
}

bool CheckCondition(int src) {
    for (int i = 0; i < cond_vec[src].size(); ++i) {
        int n = cond_vec[src][i],
            dest = GET_DEST(n),
            val = GET_VALUE(n),
            dist;
        
        if (frnd_pos[dest] == -1) continue;

        dist = abs(frnd_pos[src] - frnd_pos[dest]) - 1;

        if (IS_EQUAL(n)) {
            if (dist != val) return false;
        } else if (IS_GREATER(n)) {
            if (dist <= val) return false;
        } else if (IS_LESS(n)) {
            if (dist >= val) return false;
        } else exit(-1);
    }
    
    return true;
}

void Logic(int cnt = 0, int flag = 0) {
    if (cnt == FRIENDS_COUNT) {
        answer++;
        return;
    }
    
    for (int i = 0, n = 1; n <= 0x00ff; i++, n <<= 1) {
        if (flag & n) continue;
        frnd_pos[i] = cnt;
        if (CheckCondition(i))
            Logic(cnt + 1, flag | n);
        frnd_pos[i] = -1;
    }
}

int solution(int n, vector<string> data) {
    Init(data);
    Logic();
    return answer;
}