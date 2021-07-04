/* 완주하지 못한 선수 */

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
	string ans = "";
	unordered_map<string, int> par_map;
	unordered_map<string, int> com_map;

	int size = completion.size();

	for (int i = 0; i < size; ++i)
		com_map[completion[i]] += 1;

	size++;

	for (int i = 0; i < size; ++i)
		par_map[participant[i]] += 1;

	for (int i = 0; i < size; ++i) {
		unordered_map<string, int>::iterator iter;
		iter = com_map.find(participant[i]);

		if (iter == com_map.end() || (*iter).second != par_map[participant[i]]) {
			ans = participant[i];
			break;
		}
	}

	return ans;
}