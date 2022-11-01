#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <chrono>

//Optimize it, as few values as possible, as few lines as possible 
//check all the redundancies
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


void qs(int*a,int l,int r){
    int i;
    if(l<r){
        i=partition(a,l,r);
        qs(a,l,i-1);
        qs(a,i+1,r);
    }
}

int main()
{   
    clock_t start,end;
    int n;char c;
    scanf("%d\n",&n);
    int* a=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d ",a+i);
    }
    // start=clock();
    // qs(a,0,n-1);
    // end=clock();
    partition(a,0,n-1);

    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("%lf",(double)((end-start)/CLOCKS_PER_SEC));
    

    free(a);
    return 0;
}