/* 실패율 */

#include <string>
#include <vector>
#include <list>

struct _data { int key; double val; };

using namespace std;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	list<_data> fail;
	int stay[502] = {}, sum = 0;

	for (int i = 0; i < stages.size(); ++i) 
		stay[stages[i]]++;

	sum = stay[N + 1];

	for (int i = N; i >= 1; --i) {
		sum += stay[i];
		_data data = { i, stay[i] / (double)sum };
		fail.push_front(data);
	}

	while (fail.size() != 0) {
		list<_data>::iterator min, iter;
		iter = min = fail.begin();
		for (iter++; iter != fail.end(); iter++) {
			if ((*iter).val > (*min).val)
				min = iter;
		}
		answer.push_back((*min).key);
		fail.erase(min);
	}

	return answer;
}