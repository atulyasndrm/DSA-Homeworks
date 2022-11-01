#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
// FOR AN ARRAY!!!
int arrin(int* a,int st,int e){
    if(st==e){
        return st;
    }
    int m=(e-st)/2;
    if(a[m]>a[m+1]){
        return arrin(a,m+1,e);
    }else{
        return arrin(a,st,m);
    }
}
int main(){
int n,i,j;
vector v 
// cin>>n;
// int a[n];   
// for(j=0;j<n;j++){
//     cin>>a[j];
// }
// cout<<arrin(a,0,n-1);

// 

// FOR A MATRIX
// int main(){
// int a[n][n];
// for(i=0;i<n;i++){
//     for(j=0;j<n;j++){
//         cin>>a[i][j];
//     }
// }
// }