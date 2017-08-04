#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int f(int x) {
    if (x == 3) return 1;
    if (x < 3) return 0;
    if (x & 1) return f(x / 2) + f(x / 2 + 1);
    else return 2 * f(x / 2);
}

int main() {
    int n;
    while (scanf("%d", &n), n != 0)
        printf("%d\n", f(n));
    return 0;
}
