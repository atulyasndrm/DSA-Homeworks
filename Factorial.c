#include <stdio.h>
int main(){
    
    int n;
    scanf("%d",&n);
    int a[n]; int l=0,p=1,i;
    for(i=0;i<7;i++){
        p=p*10;
    }
    for(i=1;i<=n;i++){
        a[l]=i*a[l];
        
    }
}