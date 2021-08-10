//----------------------------------------------------------------------------------
// [ 문자열 내 마음대로 정렬하기 ] https://programmers.co.kr/learn/courses/30/lessons/12915
//----------------------------------------------------------------------------------

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
	sort(strings.begin(), strings.end(), [n](const string& a, const string& b)
            ->bool{return (a[n] == b[n]) ? a < b : a[n] < b[n];});
    return strings;
}