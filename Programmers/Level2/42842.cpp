#include <vector>
#include <math.h>

using namespace std;

int QuadraticFormula(int a, int b, int c) { return (-b - sqrt(pow(b, 2) - (a * c * 4))) / (a * 2); }

vector<int> solution(int brown, int yellow) {
    int a = 1, b = -(brown / 2) - 2, c = brown + yellow;
    int y = QuadraticFormula(a, b, c);
    int x = -y + (brown / 2) + 2;
    vector<int> answer = {x, y};
    return answer;
}