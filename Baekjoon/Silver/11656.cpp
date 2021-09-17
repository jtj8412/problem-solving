//----------------------------------------------------------------------------------
// [ 접미사 배열 ] https://www.acmicpc.net/problem/11656
//----------------------------------------------------------------------------------

#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int main() {
    priority_queue<string, vector<string>, greater<string>> pq;
    string s;

    // init
    cin >> s;

    // logic
    for (int i = 0; i < s.size(); ++i) 
        pq.push(s.substr(i, s.size() - i));

    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }
}