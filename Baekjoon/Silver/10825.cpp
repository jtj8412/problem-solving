//----------------------------------------------------------------------------------
// [ 국영수 ] https://www.acmicpc.net/problem/10825
//----------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

struct DATA {
    char name[101];
    int x1, x2, x3;
};

int main() {
    vector<DATA> vec;
    int n;
    scanf("%d", &n);
    vec.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%s %d %d %d", vec[i].name, &vec[i].x1, &vec[i].x2, &vec[i].x3);
    }
    sort(vec.begin(), vec.end(), [](const DATA& a, const DATA& b)->bool {
        if (a.x1 != b.x1) return a.x1 > b.x1;
        if (a.x2 != b.x2) return a.x2 < b.x2;
        if (a.x3 != b.x3) return a.x3 > b.x3;
        return strcmp(a.name, b.name) < 0;
    });
    for (int i = 0; i < vec.size(); ++i) {
        printf("%s\n", vec[i].name);
    }
}