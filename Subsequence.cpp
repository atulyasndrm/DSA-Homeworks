#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int main()
{
int n1; 
    string a;
   cin>>a; 
    n1=a.length();
int n2; 
int i=0,j=0;
    // getchar();
    string b;
    cin>>b;
    n2=b.length();
    string c="";
    
        while(i<n1&&j<n2){
            if(n1<n2){
                while(a[i]!=b[j]){
                    j++;
                }
                c=c+b[j]; 
                i++;
            }else{
                while(a[i]!=b[j]){
                    i++;
                }
                c=c+a[i]; 
                j++;
            }
        }
        cout<<c<<endl;
        if(b==c||a==c){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    return 0;
}