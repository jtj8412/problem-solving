/* 가장 큰 수 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct DATA {
    int num;
    string str;
    DATA(int num) {
        this->str = to_string(num);
        int n = this->str[0] - '0';
        while (num < 1000 && num != 0) {
            num *= 10; num += n;
        }
        this->num = num;
    }
};

bool compare(const DATA& a, const DATA& b) {
    if (a.num == b.num && a.str.size() + b.str.size() == 5)
        return (a.str.size() == 3) ? a.str[1] < a.str[0] : a.str[1] > a.str[0];

    return a.num > b.num;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<DATA> data_vec;

    for (int i = 0; i < numbers.size(); ++i) 
        data_vec.push_back(DATA(numbers[i]));

    sort(data_vec.begin(), data_vec.end(), compare);

    for (int i = 0; i < data_vec.size(); ++i)
        answer += data_vec[i].str;
    
    if (answer[0] == '0') return "0";

    return answer;
}