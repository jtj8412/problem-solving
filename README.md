# Problem Solving

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

