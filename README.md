# Problem Solving

#### 프로그래머스 실패

```
[Level3]

12907(거스름돈) : DP
42861(섬 연결하기) : Kruskal
43238(입국심사) : Binary Search
```

#### 크러스컬 알고리즘 (Kruskal's Algorithm)
```
최소비용신장트리 알고리즘
1. 가중치(거리) 낮은 순으로 간선 추가
2. 사이클이 발생할 경우 스킵
시간복잡도: O(ElogV)
문제: 42861
```

#### 다익스트라 알고리즘 (Dijkstra algorithm)
```
양의 가중치만을 가질 때, 하나의 정점에서 다른 모든 정점으로의 최단 경로 획득
1. 정점 위치(번호) 및, 시작 정점에서 현재 정점까지의 가중치의 합계를 담은 자료구조 생성
2. 가중치 합계의 내림차순 정렬 queue를 만들어 bfs 탐색
3. 시작 정점부터 임의의 정점까지의 최소 가중치합을 저장
4. 현재 탐색하는 정점이 기존에 저장된 가중치합보다 클 경우 무시
시간복잡도: O(NlogN)
문제: 72413
```

#### 근의 공식
```cpp
float quadratic_formula(float a, float b, float c, bool plus=true) {
    return (-b + ((plus)?1:-1) * sqrtf(b*b - a*c*4)) / (a*2);
}
```

#### 거듭제곱(2) 수열의 합
```cpp
int power_sum(int n) {
    return (n) * (n + 1) * (n * 2 + 1) / 6;
}
```

#### 거듭제곱(3) 수열의 합
```cpp
int power3_sum(int n) {
    return (n * n) * (n + 1) * (n + 1) / 4;
}
```

#### 최대공약수
```cpp
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
```

#### 최소공배수
```cpp
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
```

#### 순열
```cpp
do {
    // contents
} while (next_permutation(begin, last))
```

#### 컨테이너/배열 초기화
```cpp
std::fill(addr, addr_end, value);
std::fill_n(addr, size, value);
std::iota(begin, end, start_value);
```

#### 컨테이너/배열 최댓값(최솟값)
```cpp
std::max_element(addr, addr_end);  // pointer
std::max_element(begin, end);      // iterator
```

#### 컨테이너/배열 정렬
```cpp
std::sort(begin, end, comp);        // quick
std::stable_sort(begin, end, comp); // merge
```

#### 컨테이너/배열
```cpp
std::accumulate(addr, addr_end, init);
std::accumulate(begin, end, init);
```

#### 우선순위 큐
```cpp
template <typename T>
struct COMPARE {
    bool operator()(const T& a, const T& b) { return a > b; }
};
std::priority_queue<int, vector<int>, COMPARE<int>> pq;
```

