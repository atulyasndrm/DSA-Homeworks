#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
using namespace std;
// bool end(string sum){
//         if(sum.length()>=2&&sum[sum.size()-1]=='\n'&&sum[sum.size()-2]=='\n'){
//             return 1;
//         }
// }



int main()
{
    
    vector<int> v;
    int i=0;
    int x=1,k=0;
    int n=1000;
    char a;
    string f;
    string sum="";
    stack<char> c;
    stack<char> st[n]; 
    stack<char> fin[n];
    while(1+(scanf_s("%c",&a))){
        if(sum.length()>=2&&sum[sum.size()-1]=='\n'&&sum[sum.size()-2]=='\n'){
            break;
        }
        sum=sum+a;
    }
    while(sum[i]!='\n'){
        i++;
    }
   int  multi=(i+1);
    n=multi/4;
    while(sum[x+k*multi]!='1'){
        if(sum[x+k*multi]<='Z'&&sum[x+k*multi]>='A'){
            st[(x-1)/4].push(sum[x+k*multi]);
        }
        x=x+4;
        if(x>=multi){
            k=k+1;x=1;
        }
    }
    for(int i=0;i<n;i++){
        while(!(st[i].empty())){
            fin[i].push((char)st[i].top());
            st[i].pop();
        }
    }
    int p[3];
    while(cin>>f){
        for(int i=0;i<3;i++){
            cin>>p[i];
            if(i<2) cin>>f;
        }
        while(p[0]--){
            c.push(fin[p[1]-1].top());
            fin[p[1]-1].pop();
        }
        while(!c.empty()){
            fin[p[2]-1].push(c.top());
            c.pop();
        }
        // while(p[0]--){
        //     fin[p[2]-1].push(fin[p[1]-1].top());
        //     fin[p[1]-1].pop();
        // }
    }
    for(int i=0;i<n;i++){
        cout<<fin[i].top();
    }
    return 0;
}