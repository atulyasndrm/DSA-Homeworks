#include <iostream>
#include <vector>           
using namespace std;

int main(){
    int n;cin>>n;
    int a[n];int s[n];
    int k;
    for(k=0;k<n;k++){
        cin>>a[k];
    }
    s[0]=a[0];
    for(int i=1;i<n;i++){
        if(s[i-1]>0){
            s[i]=a[i]+s[i-1];
        }else{
            s[i]=a[i];
        }
    }  int max=0;
    for(int j=0;j<n;j++){
        if(s[j]>max){
            max=s[j];
        }
    }  
    cout<<max;  
    

}