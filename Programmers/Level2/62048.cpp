/* 멀쩡한 사각형 */

#include <math.h>

using namespace std;

long long solution(int w,int h) {
    double half_area = (double)w * h * 0.5,
        area = (double)w * h, 
        full = 0, ratio = 0, len = 0;

    if (w > h) {
        ratio = (double)h / w;
        len = w;
    } else if (w < h) {
        ratio = (double)w / h;
        len = h;
    } else {
        return area - w;
    }

    for (int i = 1; i <= len; ++i) {
        full += ceil(ratio * i);
    }

    return area - (full - half_area) * 2;
}