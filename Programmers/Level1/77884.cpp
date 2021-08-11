/* 약수의 개수와 덧셈 */

#include <string>
#include <vector>

#define MAX_LENGTH 1000

using namespace std;

vector<int>* get_prime(int right) {
    vector<int>* prime_vec = new vector<int>();
    bool not_prime[MAX_LENGTH + 1] = {};
    
    for (int i = 2; i <= right; ++i) {
        if (not_prime[i]) continue;

        for (int j = 2; i * j <= right; ++j) {
            not_prime[i * j] = true;
        }
        prime_vec->push_back(i);
    }
    return prime_vec;
}

int solution(int left, int right) {
    int answer = 0;
    vector<int>* prime_vec = get_prime(right);
    for (int i = left; i <= right; ++i) {
        int num = i;
        int mul = 1;
        vector<int> divisor_vec; 
        for (int j = 0; j < prime_vec->size(); ++j) {
            int prime = (*prime_vec)[j], cur = prime, k;
            if (prime > num) break;
            for (k = 1; num % cur == 0; ++k, cur*=prime);
            if (k != 1) divisor_vec.push_back(k - 1);
        }
        for (int j = 0; j < divisor_vec.size(); ++j) {
            mul *= (divisor_vec[j] + 1);
        }
        if (mul % 2 == 0) answer += num;
        else answer -= num;
    }

    delete(prime_vec);

    return answer;
}