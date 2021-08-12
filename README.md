# Algorithm

#### 프로그래머스 실패

```
[Level3]

12907(거스름돈)
42861(섬 연결하기)
43238(입국심사)
```

#### 크러스컬 알고리즘 (Kruskal's Algorithm)
```
최소비용신장트리 알고리즘
1. 가중치(거리) 낮은 순으로 간선 추가
2. 사이클이 발생할 경우 스킵
시간복잡도: O(ElogV)
문제: 42861
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

