#include <stdio.h>
int power(int x,int n){
    int t;
    if(n==0){
        return 1;
    }
    t=(power(x,n/2))%10;
    if(n%2==1){
        return (t*t*(x%10))%10;
    }else{
        return (t*t)%10;
    }
}
int main(){
    int x,n,p;
    scanf("%d %d",&x,&n);
    p=power(x,n);
}