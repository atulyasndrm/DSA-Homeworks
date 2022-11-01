#include <iostream>
#include <vector>           
using namespace std;

int main(){
    int n;cin>>n;
    int a[n];int s[n];
    int k;int t1,t2,t3,t4,i;
    for(k=0;k<n;k++){
        cin>>a[k];
    }
    int t=0;int max=-99999;t1=t2=t3=t4=0;
    for(i=0;i<n;i++){
        if(t>0){
            t=a[i]+t;
            t2=i;
        }else{
            t=a[i];
            t1=i;t2=i;
        }
        if(t>max){
            max=t;
            t3=t1;t4=t2;
        }
    }  i=t3;
    while(i<=t4){
        cout<<a[i]<<" ";
        i++;
    }cout<<"\n";
    // for(int j=0;j<n;j++){
    //     if(s[j]>max){
    //         max=s[j];
    //     }
    // }  
    cout<<max;  
    

}