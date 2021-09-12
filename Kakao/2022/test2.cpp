#include <string>
#include <vector>
#include <math.h>
using namespace std;

string change(int n, int b) {
    string ret;
    int r;
    r = n % b;
    n /= b;
    if (n > 0) ret = change(n, b);
    return ret + (char)(r + '0');
}

bool is_prime(long long num) {
	if (num < 2) return false;
    if ((num % 10) % 2 == 0 && num > 4) return false;//
	int len = sqrt(num);
	for (int i = 2; i <= len; ++i) {
        if (num % i == 0) return false;
    }
	return true;
}

int solution(int n, int k) {
    int answer = 0;
    string s = change(n, k);
    for (int i = 0; i < s.size(); ++i) {
        if ((i != 0 && s[i-1] != '0') || s[i] == '0') continue;
        for (int j = i; j < s.size(); ++j) {
            if (s[j] == '0') break;
            if (j != s.size() - 1 && s[j+1] != '0') continue;
            if (is_prime(stol(s.substr(i, j - i + 1)))) ++answer;
        }
    }

    return answer;
}