#include <stdio.h>
float Mean(int* a1,int s1,int e1,int* a2,int s2,int e2){
    if((e1-s1)+(e2-s2)==2||s1==e1||s2==e2){
        float mean;
        if(a1[e1]<=a2[s2]||(a1[s1]<=a2[s2]&&a2[s2]<=a1[e1]&&a1[s1]<=a2[e2])){
            mean=(a1[e1]+a2[s2])/2.0;
            printf("%d %d 1\n",a2[s2],a1[e1]);
        }else if(a2[e2]<=a1[s1]||(a2[s2]<=a1[s1]&&a1[s1]<=a2[e2]&&a2[e2]<=a1[e1])){
            mean=(a2[e2]+a1[s1])/2.0;
            printf("%d %d 2\n",a1[s1],a2[e2]);
        }else if(a1[s1]<=a2[s2]&&a2[e2]<=a1[e1]){
            mean=(a2[s2]+a2[e2])/2.0;
            printf("%d %d 3\n",a2[s2],a2[e2]);
        }else if(a2[s2]<=a1[s1]&&a1[e1]<=a2[e2]){
            printf("%d %d 4\n",a1[s1],a1[e1]);
            mean=(a1[s1]+a1[e1])/2.0;
        }
        return mean;

    }
    int mid1=(s1+e1)/2, mid2=(s2+e2)/2;
    if(a1[mid1]>a2[mid2]){
        return Mean(a1,s1,mid1,a2,mid2,e2);
    }else{
        return Mean(a1,mid1,e1,a2,s2,mid2);
    }

}

int main(){
    int n;
    scanf("%d",&n);
    int a1[n]; int a2[n];
    for(int i=0;i<n;i++){
        scanf("%d",a1+i);
    }
    for(int i=0;i<n;i++){
        scanf("%d",a2+i);
    }
    if(n%2==1){
        printf("%0.1f",Mean(a1,0,n-1,a2,0,n-1));     
    }// }else{
    //     printf("%0.1f",Mean1(a1,0,n-1,a2,0,n-1));
    // }

}