/* H-Index */

#include <string>
#include <vector>

#define MAX_ARR 10000

using namespace std;

int solution(vector<int> citations) {
    int answer = 0,
        sum = citations.size(),
        sum2 = 0,
        prev_val = 0,
        arr[MAX_ARR + 2] = {}, i = 0;

    for (int i = 0; i < citations.size(); ++i) 
        ++arr[citations[i]];

    for (i = MAX_ARR; i >= 0 && !(sum2 >= i + 1 && sum <= i + 1); --i) {
        if (arr[i]) {
            sum -= prev_val;
            sum2 += arr[i];
            prev_val = arr[i];
        } else if (arr[i + 1]) {
            sum -= prev_val;
            prev_val = 0;
        }
    }
    answer = i + 1;

    return answer;
}