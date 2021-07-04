/* 직사각형 별찍기 */

#include <iostream>
#include <string>

using namespace std;

#define STAR "*"

int main(void) {
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < b; ++i){
		for (int j = 0; j < a; ++j)
			cout << '*';
		cout << endl;
	}
}