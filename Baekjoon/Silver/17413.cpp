//----------------------------------------------------------------------------------
// [ 단어 뒤집기 2 ] https://www.acmicpc.net/problem/17413
//----------------------------------------------------------------------------------

#include <iostream>

void swap(int left, int right, char *s) {
    for (int i = 0, tmp; left + i < right - i; ++i) {
        tmp = s[left+i];
        s[left+i] = s[right-i];
        s[right-i] = tmp;
    }
}

int main() {
    char s[100001], tmp;
    int i, j, is_lock = 0, len = 0;

    fgets(s, 100001, stdin);

    for (i = 0; s[i] != '\0' && s[i] != '\n'; ++i) {
        if (is_lock) {
            if (s[i] == '>') is_lock = 0;                           // unlock
            continue;
        }

        if (s[i] == ' ' || s[i] == '<' || s[i] == '\0' || s[i] == '\n') {
            swap(i - len, i - 1, s);                                // swap
            len = 0;
            if (s[i] == '<') is_lock = 1;                           // lock
        } else {
            ++len;
        }
    }
    swap(i - len, i - 1, s);

    printf("%s\n", s);
}