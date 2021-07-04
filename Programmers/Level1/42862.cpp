/* 체육복 */

#include <string>
#include <vector>
#include <string.h>

#define MAX_NUM 32

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int arr[MAX_NUM];
	vector<int>::iterator iter;
	int ans = 0;

	for (int i = 1; i <= MAX_NUM; ++i)
		arr[i] = 1;
	for (iter = lost.begin(); iter != lost.end(); ++iter)
		arr[*iter] = 0;
    
	for (iter = reserve.begin(); iter != reserve.end();) {
		if (arr[*iter] == 0) {
			arr[*iter] = 1;
			iter = reserve.erase(iter);
		}
		else{
			++iter;
		}
	}
	for (iter = reserve.begin(); iter != reserve.end(); ++iter) {
		if (*iter != 1 && arr[*iter - 1] == 0) {
			arr[*iter - 1]++;
		}
		else {
			arr[*iter + 1]++;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (arr[i] != 0) {
			ans++;
		}
	}

	return ans;
}