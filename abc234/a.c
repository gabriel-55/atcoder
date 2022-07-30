#include<stdio.h>

int f(int t) {
    return t*t + 2*t + 3;
}

int main(void) {
    int t;
    scanf("%d", &t);

    int ans = f(f(f(t)+t)+f(f(t)));
    printf("%d\n", ans);
    return 0;
}