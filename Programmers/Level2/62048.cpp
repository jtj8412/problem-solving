/* 멀쩡한 사각형 */

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

long long solution(int w,int h) {
    long long answer = 1;
    int lcm = (w, h), w_ratio = lcm / w;
    
} 