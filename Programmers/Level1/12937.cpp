//----------------------------------------------------------------------------------
// [ 짝수와 홀수 ] https://programmers.co.kr/learn/courses/30/lessons/12937
//----------------------------------------------------------------------------------

#include <string>
std::string solution(int num) {
	return (num & 1) ? "Odd" : "Even";
}