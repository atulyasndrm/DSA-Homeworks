#include <stdio.h>
#include <stdlib.h>

void swap(int*a,int*b){
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int*a, int l,int r){
    int k=a[l],e=r,i=l+1;
    while(i<e){
        if(a[i]>k){
            swap(a+e,a+i);
            e--;
        }else{
            i++;
        }   
    }
    if(a[i]>k){
        i--;
    }
    swap(a+l,a+i);
    return i;
}

int qs(int* a,int l, int r,int i){
    int k=partition(a,l,r);
    if(k==i){
        return k;
    }else if(k<i){
        qs(a,k+1,r,i);
    }else{
        qs(a,l,k-1,i);
    }
}

int main()
{
int n;int i;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }scanf("%d",&i);
    i--;
printf("%d",a[qs(a,0,n-1,i)]);


    return 0;
}