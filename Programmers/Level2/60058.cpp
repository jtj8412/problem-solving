/* 괄호 변환 */

#include <string>
#include <vector>

using namespace std;

string logic(string w) {
    int a = 0, b = 0, is_correct = 1, i = -1;
    string u, v;

    if (w.empty()) return "";

    do {
        if (w[++i] == '(') ++a;
        else if (++b > a) is_correct = 0;
    } while (a != b);

    u = w.substr(0, i + 1); v = w.substr(i + 1, w.size() - i - 1);

    if (is_correct) return u + logic(v);

    u = u.substr(1, u.size() - 2);
    for (i = 0; i < u.size(); ++i) u[i] = (u[i] == ')') ? '(' : ')';

    return '(' + logic(v) + ')' + u;
}

string solution(string p) {
    return logic(p);
}