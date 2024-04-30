#include <stdio.h>

int main() {
    int n,a,d[1001]={0},i=1,j;
    scanf("%d",&n);
    for (;i<=n;i++) {
        scanf("%d",&a);
        for (j=i;j<=n;j++)if(!d[j]||d[j]>d[j-i]+a)d[j]=d[j-i]+a;
    }
    printf("%d",d[n]);
}