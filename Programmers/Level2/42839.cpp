/* 소수 찾기 */

#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

#define MAX_NUMBER 10000000
#define MAX_NUMBERS_SIZE 7

using namespace std;

int prime[MAX_NUMBER] = {};

void init_prime(int max_num) {
    fill_n(prime + 2, max_num - 2, 1);
    
    for (int i = 2; i < max_num; ++i) {
            if (!prime[i]) continue;

            for (int j = 2; i * j < max_num; ++j)
                prime[i * j] = 0;
    }
}

vector<string> combination(const string& str, int k) {
    vector<string> ret;
    int flag[MAX_NUMBERS_SIZE] = {};
    int str_size = str.size();

    fill_n(flag + str_size - k, k, 1);

    do {
        string elem = "";
        for (int i = 0; i < str_size; ++i) {
            if (flag[i]) elem += str[i];
        }
        ret.push_back(elem);        
    } while (next_permutation(flag, flag + str_size));

    return ret;
}

vector<int> permutation(string str) {
    vector<int> ret;

    do {
        ret.push_back(stoi(str));
    } while (next_permutation(str.begin(), str.end()));

    return ret;
}

int solution(string numbers) {
    int answer = 0,
        max_num = pow(10, numbers.size()) + 1;
    
    sort(numbers.begin(), numbers.end());    
    
    init_prime(max_num);

    for (int i = 1; i <= numbers.size(); ++i) {
        vector<string> comb_vec = combination(numbers, i);
        for (int j = 0; j < comb_vec.size(); ++j) {
            vector<int> perm_vec =  permutation(comb_vec[j]);
            for (int k = 0; k < perm_vec.size(); ++k) {
                if (prime[perm_vec[k]]) prime[perm_vec[k]] = 2;
            }
        }
    }

    for (int i = 0; i < max_num; ++i) {
        if (prime[i] == 2) answer++;
    }
    
    return answer;
}