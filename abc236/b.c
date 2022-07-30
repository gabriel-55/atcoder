#include<stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int a[4*n-1];
    for(int i = 0; i < 4*n-1; i++) {
        scanf("%d", &a[i]);
    }

    int cnt[n+1];

    for(int i = 0; i < n+1; i++) {
        cnt[i] = 0;
    }

    for(int i = 0; i < 4*n-1; i++) {
        cnt[a[i]]++;
    }

    int ans;
    for(int i = 1; i <= n; i++) {
        if(cnt[i] != 4) ans = i;
    }

    printf("%d\n", ans);
    return 0;
}