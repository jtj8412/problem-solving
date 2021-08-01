/* 이중우선순위큐 */

#include <string>
#include <vector>
#include <string.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483647 - 1
using namespace std;

int q[1000002], l = 1, r = 0;

void insert(int val) {
    int a = l, b = r, mid = (a + b) >> 1, n;
    while (!(q[mid] <= val && val <= q[mid + 1])) {
        if (q[mid] > val) b = mid - 1;
        else a = mid + 1;
        mid = (a + b) >> 1;
    }
    n = (r - (mid + 1) + 1) * 4;
    if (n > 0) memcpy(q + mid + 2, q + mid + 1, n);
    q[mid + 1] = val;
    q[++r + 1] = INT_MAX;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer = {0, 0};

    q[0] = INT_MIN; q[1] = INT_MAX;
    for (auto op : operations) {
        if (op[0] == 'I') insert(stoi(op.substr(2, op.size() - 2)));
        else if (op[2] == '-') {if (r - l + 1 > 0) q[l++]=INT_MIN;}
        else if (r - l + 1 > 0) q[r--] = INT_MAX;
    }
    if (r - l + 1 > 0) { answer[0] = q[r]; answer[1] = q[l]; }

    return answer;
}