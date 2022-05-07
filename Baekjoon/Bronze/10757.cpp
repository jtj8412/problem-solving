#include <bits/stdc++.h>
using namespace std;

#define MAX_LEN 10000
#define STRING_AT(pStr, idx) ((*pStr)[idx])

string str1_, str2_, *str1, *str2;

int main() {
	int idx = MAX_LEN - 1, len1 = 0, len2 = 0;
	bool bIsUp = false;

	cin >> str1_ >> str2_;

	if (str1_.length() >= str2_.length()) {
		str1 = &str1_;
		str2 = &str2_;
	}
	else {
		str1 = &str2_;
		str2 = &str1_;
	}

	len1 = str1->length();
	len2 = str2->length();

	for (int i = 0; i < len2; ++i) {
		int idx1 = len1 - i - 1;
		int idx2 = len2 - i - 1;

		if (bIsUp) {
			STRING_AT(str1, idx1)++;
			bIsUp = false;
		}

		if (STRING_AT(str2, idx2) != '\0') {
			STRING_AT(str1, idx1) += STRING_AT(str2, idx2) - '0';
		}

		if (STRING_AT(str1, idx1) > '9') {
			STRING_AT(str1, idx1) = '0' + (STRING_AT(str1, idx1) - '9' - 1);
			bIsUp = true;
		}
	}

	int idx1 = len1 - len2;
	while (--idx1 >= 0 && bIsUp) {
		STRING_AT(str1, idx1)++;
		if (STRING_AT(str1, idx1) > '9') {
			STRING_AT(str1, idx1) = '0' + (STRING_AT(str1, idx1) - '9' - 1);
		}
		else {
			bIsUp = false;
		}
	}

	if (bIsUp) {
		cout << "1";
	}
	cout << *str1;
}