//----------------------------------------------------------------------------------
// [ 약수의 개수와 덧셈 ] https://programmers.co.kr/learn/courses/30/lessons/77884
// 
// 어떤 숫자의 배수가 n일 경우 n의 약수를 하나 추가한다 (++arr[n]) 
//----------------------------------------------------------------------------------

int solution(int left, int right) {
    int answer = 0, arr[1001] = {}, i, j;
    
    for (i = 1; i <= right; ++i) {
        for (j = (left / i) * i; j <= right; j += i) ++arr[j];
    }
    
    for (i = left; i <= right; ++i) answer += (arr[i] & 1) ? -i : i;

    return answer;
}