//----------------------------------------------------------------------------------
// [ 위클리 챌린지 2주차 ] https://programmers.co.kr/learn/courses/30/lessons/83201
//
// 본인의 점수 내에서 스스로를 평가한 점수가 유일한 최고점 또는 최저점인지 확인하려면
// i학생이 i학생을 평가한 점수를 기준으로 '큼(gt)', '같음(eq)', '작음(lt)' 갯수를 센다
// 같은 점수가 1개이고, 본인 평가 점수보다 큰/작은 점수의 갯수가 본인을 제외한 학생 수 일때
// '유일한 최고점' 또는 '유일한 최저점' 으로 판단한다
//----------------------------------------------------------------------------------

#include <string>
#include <vector>
using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "", sscores = "FFFFFDDCBAA";
    int i, j, gt, lt, eq, size = scores.size();
    float sum, avg;

    for (i = 0; i < size; ++i) {
        for (j = gt = lt = eq = sum = 0; j < size; ++j) {
            if (scores[j][i] > scores[i][i]) ++gt;
            else if (scores[j][i] < scores[i][i]) ++lt;
            else ++eq;
            sum += scores[j][i];
        }
        if (eq == 1 && (lt == size - 1 || gt == size - 1)) avg = (sum - scores[i][i]) / (size - 1);
        else avg = sum / size;
        answer += sscores[avg / 10];
    }

    return answer;
}