/* 
[ N-Queen ]

- 나의 풀이
dfs 로직
위에서부터 차례대로 퀸을 배치하면 좌측아래(left), 가운데(mid), 우측아래(right)가 배치 불가능 영역이 됨
배치 불가능 영역은 비트마스크로 표시
아래로 칸을 거듭할수록, left와 right는 비트시프트를 이용해 배치 불가능 영역을 한칸씩 이동
*/

#include <vector>
using namespace std;

int logic(int n, int cnt = 0, int left = 0, int mid = 0, int right = 0) {
    int disable = left | mid | right, sum = 0, bit;
    if (cnt == n) return 1;
    for (int i = 0; i < n; ++i) {
        bit = (1 << i);
        if (bit & disable) continue;
        sum += logic(n, cnt + 1, (left | bit) >> 1, (mid | bit), (right | bit) << 1);
    }
    return sum;
}
int solution(int n) { return logic(n); }