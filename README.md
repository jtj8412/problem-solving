# Algorithm

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

#### 컨테이너 초기화
```cpp
std::iota(begin, end, start_value);
```

#### 컨테이너/배열 정렬
```cpp
std::sort(begin, end, comp);
```

