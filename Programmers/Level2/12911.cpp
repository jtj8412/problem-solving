/* 다음 큰 숫자 */

int bit_size(int n) {
    int cnt = 0, mul = 1 << 20;
    while ((mul >>= 1) != 0) {
        if (mul & n) ++cnt;
    }
    return cnt;
}

int solution(int n) {
    int cnt = bit_size(n), tmp = 0, mul = 1 << 20;
    while (cnt != tmp) tmp = bit_size(++n);
    return n;
}
