#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int min(int a,int b){
    if(a>b){
        return b;
    }else{
        return a;
    }
}
int minti(int* a,int start,int end){
    if(end-start==1){
        return min(a[start],a[end]);
    }if(start==end){
        return a[start];
    }
return min(minti(a,start,start+(end-start)/2),minti(a,(start+(end-start)/2)+1,end));
}
int n,i;
int main(){
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++){
    scanf("%d",a+i);
}
printf("%d",minti(a,0,n-1));
}