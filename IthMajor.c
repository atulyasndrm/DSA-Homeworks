#include<stdio.h>
#include<stdlib.h>
//Optimize it, as few values as possible, as fer lines as possible, 
//check all the redundancies
void partition(int* a, int l, int r){
    int step=0;
    int k=a[l]; int s=0,e=r;
    int i=l+1;int t;int no=l;
    while(i<e){
        if(a[i]>k){
            t=a[i];
            a[i]=a[e];
            a[e]=t;
            e--;
        }else if(a[i]<k){
            i++;
        }else if(a[i]==k){
            t=a[no];
            a[no]=k;
            a[i]=t;
            no++;i++;
        }
        step++;   
    }
    printf("%d\n",step);
    if(a[i]>k){
        i--;
    }
    for(int p=0;p<no;p++){
        a[l+p]=a[l+i-p];
        a[l+i-p]=k;
    }
}





int main()
{
    int n;
    scanf("%d",&n);
    int* a=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    partition(a,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    free(a);
    return 0;
}