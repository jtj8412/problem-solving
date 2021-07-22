/* 숫자의 표현 */

int solution(int n) {
    int answer = 0, i;
    float val = 1;

    for (i = 2; val >= 1.f; ++i) {
        n -= (i - 1);
        val = (float)n / i;
        if (val == (int)val) ++answer;
    }
    if (n != 0) ++answer;

    return answer;
}