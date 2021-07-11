/* 더 맵게 */

#include <vector>
#include <map>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    multimap<unsigned, int> sco_map;
    multimap<unsigned, int>::iterator iter, prev;
    int sco_size = scoville.size();

    for (int i = 0; i < sco_size; ++i) {
        sco_map.insert(make_pair(scoville[i], 1));
    }
    
    iter = sco_map.begin();
    while (sco_size > 1 && iter->first < K) {
        prev = iter; ++iter;
        sco_map.insert(make_pair(prev->first + iter->first + iter->first, 0));
        iter = sco_map.erase(prev, ++iter);
        answer++;
        sco_size--;
        
    }
    
    if (sco_map.begin()->first < K) 
        answer = -1;
    
    return answer;
}


