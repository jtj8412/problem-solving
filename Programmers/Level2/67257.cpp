/* 수식 최대화 */

#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

long long add(long long a, long long b) { return a + b; }
long long sub(long long a, long long b) { return a - b; }
long long mul(long long a, long long b) { return a * b; }

void calculate(list<long long> &num_list, list<long long> &exp_list, int exp, long long (*cal)(long long, long long)) {
    list<long long>::iterator n_iter, e_iter, n_prev = num_list.begin();
    for (n_iter = ++num_list.begin(), e_iter = exp_list.begin(); e_iter != exp_list.end(); ++n_iter, ++e_iter) {
        if (*e_iter != exp) {n_prev = n_iter; continue; }
        *n_iter = cal(*n_prev, *n_iter);
        num_list.erase(n_prev);
        e_iter = --exp_list.erase(e_iter);
        n_prev = n_iter;
    }
}

long long solution(string expression) {
    long long answer = 0, num = 0, res, exp[] = {'*', '+', '-'};
    list<long long> num_list, exp_list, num_copy, exp_copy;
    long long (*cal)(long long, long long), i;

    for (int i = 0; i <= expression.size(); ++i) {
        if (isdigit(expression[i])) { 
            num *= 10;
            num += expression[i] - '0'; 
        } else { 
            num_list.push_back(num); 
            exp_list.push_back(expression[i]);
            num = 0; 
        }
    }
    exp_list.pop_back();

    do {
        num_copy.assign(num_list.begin(), num_list.end()); 
        exp_copy.assign(exp_list.begin(), exp_list.end());
        for (i = 0; i < 3; ++i) {
            if (exp[i] == '+') cal = add;
            else if (exp[i] == '-') cal = sub;
            else cal = mul;
            calculate(num_copy, exp_copy, exp[i], cal);
        }
        res = abs(num_copy.front());
        if (answer < res) answer = res;
    } while (next_permutation(exp, exp + 3));

    return answer;
}