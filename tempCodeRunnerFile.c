#include <stdio.h>
const int INT_MAX = 0x7fffffff;
int main() {
    short a = -1;
    unsigned short b = a;
    unsigned int c = a;
    printf("%d\n", b);
    printf("%u\n", c);
    long long d = ((long long)1 << 32) - 1;
    printf("%lld\n", d);
    return 0;
}