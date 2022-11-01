#include <stdio.h>
int Peak(int *a,int st,int e){
    int mid=(st+e)/2; 
    // printf("%d %d %d\n",st,mid,e);
    if(a[mid]>a[mid-1]&&a[mid+1]<a[mid]){
        return mid;
    }else{ 
        if(a[mid]>a[mid-1]&&a[mid+1]>a[mid]){
            return Peak(a,mid,e);
        }else{
            return Peak(a,st,mid);
        }
        
    }
}
int main(){
    int n,i,l,r,mid;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",a+i);
    }
    // l=0;r=n-1;
    // while(1){
    //     mid=(l+r)/2;
    //     if(a[mid]>a[mid-1]&&a[mid+1]>a[mid]){
    //         l=mid;
    //     }else if(a[mid]<a[mid-1]&&a[mid+1]<a[mid]){
    //         r=mid;
    //     }else{
    //         break;
    //     }
    // }
    // printf("%d",a[mid]);
    printf("%d",a[Peak(a,0,n-1)]);
}