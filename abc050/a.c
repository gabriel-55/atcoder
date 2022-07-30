#include<stdio.h>

int main(void) {
    int a, b;
    char op;
    scanf("%d %c %d", &a, &op, &b);
    
    int ans;
    if(op == '+') ans = a + b;
    else ans = a - b;
    printf("%d\n", ans);

    return 0;
}