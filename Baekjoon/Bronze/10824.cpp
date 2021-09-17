//----------------------------------------------------------------------------------
// [ 네 수 ] https://www.acmicpc.net/problem/10824
//----------------------------------------------------------------------------------

#include <iostream>
#include <math.h>

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%lld", a * (long long)pow(10, (int)log10(b) + 1) + c * (long long)pow(10, (int)log10(d) + 1) + b + d);
}