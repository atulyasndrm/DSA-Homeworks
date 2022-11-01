#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int t=*a;
    *a=*b;
    *b=t;
}


int ex(int* a, int n){
    swap(a,a+n-1);
    int t=0, k; 
    while((t<(n-1)/2)&&((2*t+1<n-1 && a[t]>a[2*t+1])||(2*t+2<n-1 && a[t]>a[2*t+2]))){
        if(2*t+2>=n-1||a[2*t+1]<a[2*t+2]){
                k=2*t+1;         
        }else{
                k=2*t+2;
        }   
        if(a[t]>a[k]){
            swap(a+t,a+k);
        }
        t=k;
    }
    return a[n-1];   
}


void insert(int *a,int n,int x){
    a[n]=x;
    while(n>0&&(a[n]<a[(n-1)/2])){
        swap(a+n,a+((n-1)/2));
        n=(n-1)/2;
    }
}


void heapify(int* a, int n){
   int t=(n-1)/2, k, z;
   z=t; 

    while(z>=0){
        t=z;
        while((t<=(n-1)/2)&&((2*t+1<n && a[t]>a[2*t+1])||(2*t+2<n && a[t]>a[2*t+2]))){
            if(2*t+2>=n||a[2*t+1]<a[2*t+2]){
                    k=2*t+1;         
            }else{
                    k=2*t+2;
            }
            if(a[t]>a[k]){
                swap(a+t,a+k);
            }
            t=k;
        }
        z--;
    }
}


int main(){
    
    int n,i;
    scanf("%d\n",&n);
    int a[n+1];
    for(i=0;i<n;i++){
        scanf("%d",a+i);
    }
    int x;
    scanf("%d",&x);
    heapify(a,n);
    for(i=n;i>0;i--){
        printf("%d ",ex(a,i));
    }

    return 0;
}