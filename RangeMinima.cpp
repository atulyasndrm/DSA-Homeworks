#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int log[n];int po[n];int i,p=1,s=0;
    for(i=0;i<n;i++){
        if(i==p){
            log[i]=p; po[i]=s;s++;p*=2;
        }else{
            log[i]=p/2; po[i]=s;
        }
    }
    for(i=0;i<n;i++){
        printf("%d ",log[i]);
    }cout<<"\n";
    for(i=0;i<n;i++){
        printf("%d ",po[i]);
    }
}