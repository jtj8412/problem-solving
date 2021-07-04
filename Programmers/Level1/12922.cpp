/* 수박수박수박수박수박수? */

#include <string>
#include <vector>

using namespace std;

const string soobak = "수박";
const string soo = "수";


string solution(int n) {
	string ret = soobak;
	int len = 2;

	if (n == 1) return soo;

	while (len + len < n) {
		ret += ret;
		len += len;
	}

	if (len != n) ret += solution(n - len);

	return ret;
}