#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int minti(int* a,int st,int end){
    if(a[st]==1){
        return st;
    }
    if(a[st]==0&&st==end){
        return -1;
    }
if(a[st+((end-st)/2)]==1){
    return minti(a,st,st+((end-st)/2));
}else{
    return minti(a,st+((end-st)/2)+1,end);
}
}
int lin(int*a,int p,int q){
   int l=p,r=q;int mid;
    while(!(a[l])){
        mid=l+((r-l)/2);
        if(a[mid]==1){
            r=mid;
        }else{
            l=mid+1;
        }
    }return l;
}
int main(){
    int n,i,j,k;
scanf("%d\n",&n);
int a[n];
for(i=0;i<n;i++){
    scanf("%d",a+i);
}
// for(j=0;j<n;j++){
//     a[j]=1;
// }
// for(j=0;j<n;j++){
//        printf("%d",a[j]);
//     }printf("\n");
// for(i=2;i<n;i++){
// for(k=0;k<n;k++){
//     for(j=0;j<k;j++){
//         a[j]=0;
//     }
//     for(j=k;j<n;j++){
//         a[j]=1;
//     }
//     // for(j=0;j<n;j++){
//     //    printf("%d",a[j]);
//     // }printf("\n");
    // printf("%d\n",minti(a,0,n-1));
    printf("%d\n",lin(a,0,n-1));
// }
// }

}