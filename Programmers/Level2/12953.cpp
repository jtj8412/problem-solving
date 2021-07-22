/* N개의 최소공배수 */

#include <vector>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int solution(std::vector<int> arr) {
    int answer = 1;

    for (int i = 0; i < arr.size(); ++i) {
        if (answer > arr[i]) answer = lcm(answer, arr[i]);
        else answer = lcm(arr[i], answer);
    }

    return answer;
}