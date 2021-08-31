//----------------------------------------------------------------------------------
// [ 위클리 챌린지 5주차 ] https://programmers.co.kr/learn/courses/30/lessons/84512
//----------------------------------------------------------------------------------

#include <string>
using namespace std;

int answer = 0, iWord[5] = {}, arr[5] = {}, is_end = 0;

void logic(int idx = 0) {
    if (idx == 5) return;
    for (int i = 1, j; i <= 5 && !is_end; ++i) {
        arr[idx] = i;
        ++answer;
        for (j = 0; j < 5; ++j) {
            if (iWord[j] != arr[j]) break;
        }
        if (j == 5) is_end = 1;
        if (idx != 4) {
            logic(idx + 1);
            arr[idx+1] = 0;
        }
    }
}

int solution(string word) {

    for (int i = 0; i < word.size(); ++i) {
        if (word[i] == 'A') iWord[i] = 1;
        else if (word[i] == 'E') iWord[i] = 2;
        else if (word[i] == 'I') iWord[i] = 3;
        else if (word[i] == 'O') iWord[i] = 4;
        else if (word[i] == 'U') iWord[i] = 5;
    }
    
    logic();

    return answer;
}
