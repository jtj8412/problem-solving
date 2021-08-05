/* 
[ 길 찾기 게임 ]

- 나의 해설
1. y축 내림차순, x축 오름차순 정렬
2. nodeinfo (x, y) 구성변경 -> (x, y, vertex, max_x)    // max_x는 어떤 노드가 자식 노드일 수 있는 x의 최대 범위
3. 임의의 두 노드가 부모,자식 관계인지 확인
 2-1. 자식의 y좌표가 부모의 y좌표에 한단계 아래
 2-2. 자식의 x좌표가 부모의 max_x보다 작음
4. 부모 노드에 자식 노드 삽입
 4-1. 부모 노드보다 x좌표가 작을 경우, 좌측에 삽입
 4-2. 부모 노드보다 x좌표가 클 경우, 우측에 삽입
5. 자식 노드의 max_x 설정
 5-1. 좌측 노드일 경우, max_x는 부모의 x값
 5-2. 우측 노드일 경우, max_x는 부모의 max_x값
*/

#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> answer(2);
vector<pair<int, int>> edge(10001);

void preorder(int vertex) {
    if (vertex == 0) return;
    answer[0].push_back(vertex);
    preorder(edge[vertex].first);
    preorder(edge[vertex].second);
}

void postorder(int vertex) {
    if (vertex == 0) return;
    postorder(edge[vertex].first);
    postorder(edge[vertex].second);
    answer[1].push_back(vertex);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    int i, j;
    for (int i = 0; i < nodeinfo.size(); ++i) nodeinfo[i].push_back(i + 1);
    sort(nodeinfo.begin(), nodeinfo.end(), [](const vector<int> &a, const vector<int> &b)->
        bool{return (a[1]==b[1])?a[0]<b[0]:a[1]>b[1];});
    nodeinfo[0].push_back(100000);
    for (int i = 0, j = 1; j < nodeinfo.size(); ++j) {
        if (nodeinfo[j][1] != nodeinfo[j - 1][1]) {
            while (nodeinfo[i][1] != nodeinfo[j - 1][1]) ++i;
        }
        while (nodeinfo[j][0] > nodeinfo[i][3]) ++i;
        if (nodeinfo[j][0] < nodeinfo[i][0]) {
            edge[nodeinfo[i][2]].first = nodeinfo[j][2];
            nodeinfo[j].push_back(nodeinfo[i][0]);
        }
        else {
            edge[nodeinfo[i][2]].second = nodeinfo[j][2];
            nodeinfo[j].push_back(nodeinfo[i][3]);
        }
    }
    preorder(nodeinfo[0][2]);
    postorder(nodeinfo[0][2]);
    return answer;
}