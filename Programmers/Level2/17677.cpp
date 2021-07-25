/* [1차] 뉴스 클러스터링 */

#include <string>
#include <cctype>
#include <algorithm>
#include <unordered_map>

using namespace std;

void make_set(unordered_map<string, int> &um, const string &s) {
    for (int i = 0; i < s.size() - 1; ++i) {
        if (isalpha(s[i]) && isalpha(s[i + 1])) ++um[s.substr(i, 2)];
    }
}
int solution(string str1, string str2) {
    int inter = 0, uni = 0;
    unordered_map<string, int> um1, um2;
    
    transform(str1.cbegin(), str1.cend(), str1.begin(), ::toupper);
    transform(str2.cbegin(), str2.cend(), str2.begin(), ::toupper);
    make_set(um1, str1); make_set(um2, str2);

    for (auto iter : um1) {
        if (um2[iter.first] == 0) {
            uni += iter.second;
        } else {
            uni += max(iter.second, um2[iter.first]);
            inter += min(iter.second, um2[iter.first]);
            um2.erase(iter.first);
        }
    }
    for (auto iter : um2) uni += iter.second;
    
    return (uni == 0) ? 65536 : ((float)inter / uni) * 65536;
}