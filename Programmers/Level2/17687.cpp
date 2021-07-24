/* [3차] n진수 게임 */

#include <string>
#include <math.h>

using namespace std;

int maximum(int n, int size) { return pow(n, size - 1) * size * (n - 1); }
int value(int n, int p, int size) { return pow(n, size - 1) + (p - 1) / size + ((size == 1) ? -1 : 0); }
int count(int p, int size) { return (p - 1) % size; }

string solution(int n, int t, int m, int p) {
    string answer = "";
    int size = 1,
        max = maximum(n, size) + 1,
        val, cnt, mul;

    while (t-- > 0) {
        while (max < p) {
            p -= max;
            max = maximum(n, ++size);
        }

        val = value(n, p, size);
        cnt = count(p, size);

        mul = pow(n, size - 1);
        while (cnt-- != 0) { (val %= mul); (mul /= n); }
        val /= mul;
        p += m;

        answer += (val > 9) ? 'A' + (val - 10) : '0' + val;
    }

    return answer;
}