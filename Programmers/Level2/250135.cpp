#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>
#include <stack>
#include <map>

using namespace std;

/*

1분: 2번 알림 (시침1, 분침1)
1시간: 120번 알림 (2 x 60분)
24시간: 2880번 알림 (120 x 24시간)

[예외 상황]
case1: 00:00:00 ~ 00:01:00: 1번 알림 (시침, 분침, 초침 겹치므로)
case2-1: XX:59:00 ~ XX:00:00: 1번 알림 (분침, 초침이 다음 시간이 될 때까지 안겹침)
case2-2: 11:59:00 ~ 00:00:00: 0번 알림 (시침, 분침, 초침이 다음 시간이 될 때까지 안겹침)

[예시]
00:00:00 ~ 23:59:59 (시계 두 번 순회)
- 24시간인 2880번을 기준으로 계산
- case1 에 의해 -2
- case2-1 에 의해 -24
- case2-2 에 의해 -2
즉 2880 - 24 = 2852번

[다른 풀이]
24시간은 86400초이기 때문에
86400을 순회하면서 판단하는 것이 구현이 더 빠르고 복잡하지 않을 것으로 예상

*/

const int ALARM_COUNT_PER_MIN = 2;
const int ALARM_COUNT_PER_HOUR = ALARM_COUNT_PER_MIN * 60;

int calculateHourRange(int fromHour, int toHour)
{
    if (fromHour > toHour)
    {
        return 0;
    }

    int hourLength = (toHour - fromHour + 1);
    int alarmCount = hourLength * ALARM_COUNT_PER_HOUR;

    // case2-1
    alarmCount -= hourLength;

    // case1
    if (fromHour == 0)
    {
        alarmCount--;
    }
    if (fromHour <= 12 && 12 <= toHour)
    {
        alarmCount--;
    }

    //case2-2
    if (fromHour <= 11 && 11 <= toHour)
    {
        alarmCount--;
    }
    if (fromHour <= 23 && 23 <= toHour)
    {
        alarmCount--;
    }
    
    return alarmCount;
}

int calculateSecondRange(int hour, int min, int fromSec, int toSec)
{
    // case1
    if ((hour == 0 || hour == 12) && min == 0 && fromSec == 0)
    {
        return 1;
    }

    int alarmCount = 0;

    int hourPosition = ((hour % 12) * 5) + (min / 12);
    if (fromSec <= hourPosition && hourPosition < toSec)
    {
        alarmCount++;
    }

    if (fromSec <= min && min < toSec)
    {
        alarmCount++;
    }
    else if (min == 0 && fromSec == 0)
    {
        alarmCount++;
    }

    return alarmCount;
}

int calculateMinuteRange(int hour, int fromMin, int fromSec, int toMin, int toSec)
{
    int alarmCount = 0;

    if (fromMin == toMin)
    {
        alarmCount += calculateSecondRange(hour, fromMin, fromSec, toSec);
    }
    else
    {
        alarmCount += calculateSecondRange(hour, fromMin, fromSec, 60);
        alarmCount += calculateSecondRange(hour, toMin, 0, toSec);
        if (fromMin + 1 < toMin)
        {
            alarmCount += (toMin - fromMin - 1) * ALARM_COUNT_PER_MIN;
        }
    }

    return alarmCount;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;

    if (h1 == h2)
    {
        answer += calculateMinuteRange(h1, m1, s1, m2, s2);
    }
    else
    {
        answer += calculateHourRange(h1 + 1, h2 - 1);
        answer += calculateMinuteRange(h1, m1, s1, 59, 59);
        answer += calculateMinuteRange(h2, 0, 0, m2, s2);
    }

    return answer;
}