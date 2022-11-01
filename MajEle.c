#include <stdio.h>
int main(){
    int n,i,ct=0,ele,count=0;
    scanf("%d",&n);
    int a[n];
for(i=0;i<n;i++){
    scanf("%d",a+i);
}
for(i=0;i<n;i++){
    if(!ct){
        ele=a[i];
        ct=1;
    }else{
        if(a[i]!=ele){
            ct--;
        }else{
            ct++;
        }
    }
}
for(i=0;i<n;i++){
    if(a[i]==ele){
        count++;
    }
}
if(count>n/2){
    printf("YES,%d",count);
}else{
    printf("NO");
}
}