#include <iostream>

int main() {
    int n, k, i, coin[10], ans = 0;

    scanf("%d %d", &n, &k);
    for (i = 0; i < n; ++i) scanf("%d", &coin[i]);

    for (i = n - 1; i >= 0 && k != 0; --i) {
        ans += k / coin[i];
        k %= coin[i];
    }
    
    printf("%d", ans);
}