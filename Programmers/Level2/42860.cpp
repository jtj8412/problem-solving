/* 조이스틱 */

#include <string>
#include <vector>

using namespace std;

int alphabet(char ch) {
    int a = ch - 'A';
    int b = 'Z'- ch + 1;
    return min(a, b);
}

int solution(string name) {
    int answer = 0,
        name_size = name.size(),
        min = name_size,
        vec_size, i;
    vector<int> notA_vec;

    for (i = 0; i < name_size; ++i) {
        if (name[i] == 'A') continue;
        answer += alphabet(name[i]);
        notA_vec.push_back(i);
    }
    vec_size = notA_vec.size();

    for (int i = 0; i < vec_size - 1; ++i) {
        int l = (notA_vec[i] * 2) + (name_size - notA_vec[i + 1]);
        int r = ((name_size - notA_vec[i + 1]) * 2) + notA_vec[i];

        if (l < min) min = l;
        if (r < min) min = r;
    }
    answer += min;

    return answer;
}