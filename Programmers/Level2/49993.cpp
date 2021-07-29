/* 스킬트리 */

#include <string>
#include <vector>
#include <algorithm>

#define SKILL_SIZE 26

using namespace std;

int solution(string skill, vector<string> tree_vec) {
    int answer = 0,
        skill_size = skill.size(),
        tree_vec_size = tree_vec.size(),
        skill_arr[SKILL_SIZE] = {},
        i, j, cur;

    fill_n(skill_arr, SKILL_SIZE, -1);
    for (i = 0; i < skill_size; ++i)
        skill_arr[skill[i] - 'A'] = i;

    for (i = 0; i < tree_vec_size; ++i) {
        int str_size = tree_vec[i].size();
        cur = 0;

        for (j = 0; j < str_size; ++j) {            
            int idx = skill_arr[tree_vec[i][j] - 'A'];
            if (!(idx == cur || idx == -1)) break;
            if (idx == cur) ++cur;
        }

        if (j == str_size)
            ++answer;
    }

    return answer;
}