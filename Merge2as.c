#include <stdio.h>
int main(){
    int n1,n2,l1,l2,i,n;
    scanf("%d %d",&n1,&n2);
    int a[n1];
    int b[n2];
    for(i=0;i<n1;i++){
        scanf("%d",a+i);
    }
    for(i=0;i<n2;i++){
        scanf("%d",b+i);
    }i=0;
    int c[n1+n2];l1=0;l2=0;
    while(l1<n1||l2<n2){
        if(l1<n1&&l2<n2){
            if(a[l1]>=b[l2]){
                c[i]=b[l2];
                l2++;
            }else{
                c[i]=a[l1];
                l1++;
            }
        }
        else if(l1==n1){
            c[i]=b[l2];
            l2++;
        }
        else if(l2==n2){
            c[i]=a[l1];
            l1++;
        }
        i++;
    }
    for(i=0;i<n1+n2;i++){
        printf("%d ",c[i]);
    }

}