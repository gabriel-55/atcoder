#include<stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int ok = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(4*i+7*j == n) ok = 1;
        }
    }

    if(ok == 1) printf("Yes\n");
    else printf("No\n");
    return 0;
}