/* 주식가격 */

#include <vector>
#include <list>

using namespace std;

struct Solve
{
	int price;
	int* count;
	Solve(int _price, int* _count) : price(_price), count(_count) {}
};

vector<int> solution(vector<int> prices) {
    int pricesLen = prices.size();
	vector<int> answer;
	list<Solve> solveList;
	list<Solve>::iterator iter, iterEnd, iterErase;

	answer.resize(prices.size());

	for (int i = 0; i < pricesLen; ++i)
	{
		iterEnd = solveList.end();
		for (iter = solveList.begin(); iter != iterEnd; ++iter)
		{
			*(iter->count) += 1;

			if (iter->price <= prices[i]) continue;

			iterErase = iter;
			iter--;
			solveList.erase(iterErase);
		}
		solveList.push_back(Solve(prices[i], &answer[i]));
	}

	return answer;
}