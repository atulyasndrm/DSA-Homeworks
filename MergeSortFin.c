#include<stdio.h>
#include<stdlib.h>
int* join(int*a,int l1,int r1,int l2,int r2){
    int * c=(int*)malloc(sizeof(int)*(r2-l1+1));int k=0;
    while(l1<=r1&&l2<=r2){
        if(a[l1]<a[l2]){
            c[k]=a[l2];
            l2++;k++;
        }else{
            c[k]=a[l1];
            l1++;k++;
        }
    }
    while(l1<=r1){
        c[k]=a[l1];
        l1++;k++;
    }
    while(l2<=r2){
        c[k]=a[l2];
        l2++;k++;
    }
    return c;
}

void mr(int* a, int l, int r){
    if(l==r){
        return;
    }
    int mid=(l+r)/2;
    mr(a,l,mid);mr(a,mid+1,r);
    int* c=join(a,l,mid,mid+1,r);
    for(int i=l;i<=r;i++){
        a[i]=c[i-l];
    }
    free(c);

}

int main()
{   int n; 
    scanf("%d",&n);
    int* a=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    mr(a,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    free(a);
    
    return 0;
    
}