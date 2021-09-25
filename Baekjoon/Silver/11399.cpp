//----------------------------------------------------------------------------------
// [ ATM ] https://www.acmicpc.net/problem/11399
//----------------------------------------------------------------------------------

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, arr[1000], answer = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) 
        scanf("%d", arr + i);
    sort(arr, arr + n);
    for (int i = 0, val = 0; i < n; ++i) {
        val += arr[i];
        answer += val;
    }
    printf("%d\n", answer);
}