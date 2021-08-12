//----------------------------------------------------------------------------------
// [ 자물쇠와 열쇠 ] https://programmers.co.kr/learn/courses/30/lessons/60059
//
// 1. 2차원 배열인 key와 lock을 1차원 배열의 flag 형태로 바꾼다 (key_flag, lock_flag)
// 2. key를 -(N-1) ~ (N-1)번 시프트하여 행마다 lock과의 적합성 체크
// 3. 한 행의 적합성을 체크할때, key_flag 와 lock_flag 의 모든 플래그가 서로 달라야한다
//    따라서 key_flag[j] ^ lock_flag[j] 를 수행한다. 
//----------------------------------------------------------------------------------

#include <vector>
using namespace std;

void init_flag(int flag[], vector<vector<int>> &board) {
    for (int i = 0, size = board.size(); i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (board[i][j]) flag[i] |= (1 << j);
        }
    }
}

bool check(int key_flag[], int lock_flag[], int lock_size, int lock_mask) {
    int i, j;
    for (i = 0; i < lock_size; ++i) {
        for (j = 0; j < lock_size; ++j) {
            if (((key_flag[j] << i) & lock_mask ^ lock_flag[j]) != lock_mask) break;
        }
        if (j == lock_size) return true;
        for (j = 0; j < lock_size; ++j) {
            if (((key_flag[j] >> i) & lock_mask ^ lock_flag[j]) != lock_mask) break;
        }
        if (j == lock_size) return true;
    }
    return false;
}

void rotate(int lock_flag[], int lock_size) {
    int tmp[20], i, j, sum;
    copy(lock_flag, lock_flag + lock_size, tmp);

    for (i = 0; i < lock_size; ++i) {
        for (j = lock_size - 1, sum = 0; j >= 0; --j) {
            if (tmp[j] & (1 << i)) sum |= (1 << (lock_size - j - 1));
        }
        lock_flag[i] = sum;
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int key_flag[60] = {}, lock_flag[20] = {}, i, j, 
        lock_mask = (1 << lock.size()) - 1;

    init_flag(key_flag + 20, key); init_flag(lock_flag, lock);

    for (i = 0; i < 4; ++i) {
        for (j = 20 - lock.size(); j < 20 + lock.size(); ++j) {
            if (check(key_flag + j, lock_flag, lock.size(), lock_mask)) return true;
        }
        rotate(lock_flag, lock.size());
    }

    return false;
}