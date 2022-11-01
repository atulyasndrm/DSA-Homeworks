#include<stdio.h>
#include<stdlib.h>
//Optimize it, as few values as possible, as fer lines as possible, 
//check all the redundancies
int main()
{
    int n;
    scanf("%d",&n);
    int* a=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    int step=0;
    int k=a[0]; int s=0,e=n-1;
    int i=1;int t;int no=1;
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
        a[p]=a[i-p];
        a[i-p]=k;
    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    free(a);
    return 0;
}