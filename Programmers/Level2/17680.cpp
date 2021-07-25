/* [1차] 캐시 */

#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0, 
        size = cities.size(), i;
    unordered_map<string, list<string>::iterator> um;
    unordered_map<string, list<string>::iterator>::iterator iter;
    list<string> cache_list;

    if (cacheSize == 0) return size * 5;

    for (i = 0; i < size; ++i)
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);

    for (i = 0; i < size; ++i) {
        if ((iter = um.find(cities[i])) != um.end() && iter->second != cache_list.end()) {
            cache_list.erase(iter->second);
            answer += 1;
        } else {
            if (cache_list.size() == cacheSize) {
                um[cache_list.front()] = cache_list.end();
                cache_list.pop_front();
            }
            answer += 5;
        }
        cache_list.push_back(cities[i]);
        um[cities[i]] = --cache_list.end();
    }

    return answer;
}