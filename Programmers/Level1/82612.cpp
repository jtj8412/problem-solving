//----------------------------------------------------------------------------------
// [ 위클리 챌린지 1주차 ] https://programmers.co.kr/learn/courses/30/lessons/82612
//
// price + 2price + 3price ... count*price 
//     = price(1 + 2 + 3 .. count) 
//     = price * count * (count + 1) / 2
//----------------------------------------------------------------------------------

long long solution(int price, int money, int count)
{
    long long answer = (((long long)price * count * (count + 1)) >> 1) - money;
    if (answer < 0) answer = 0;
    return answer;
}