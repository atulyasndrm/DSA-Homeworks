#include <stdio.h>
int main(){
    long long int n=0,i=0,t=0,sum=0;
    scanf("%lld",&n);
    long long int a[n];
    for(i=0;i<n-1;i++){
        scanf("%d",&t);
        sum=sum+t;
    }
    printf("%lld",n*(n+1)/2-sum);
}