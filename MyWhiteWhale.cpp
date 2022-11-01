#include <iostream>
using namespace std;


typedef struct node{
    long long int x,y,E,tot,f;
}nd;


nd* join(nd*a,int l1,int r1,int l2,int r2){
    nd * c=(nd*)malloc(sizeof(nd)*(r2-l1+1));int k=0;
    while(l1<=r1&&l2<=r2){
        if(a[l1].y<a[l2].y){
            c[k]=a[l2];
            l2++;k++;
        }else{
            c[k]=a[l1];
            l1++;k++;
        }
    }
    while(l1<=r1){
        c[k]=a[l1];
        l1++;k++;
    }
    while(l2<=r2){
        c[k]=a[l2];
        l2++;k++;
    }
    return c;
}

void mr(nd* a, int l, int r){
    if(l==r){
        return;
    }
    int mid=(l+r)/2;
    mr(a,l,mid);mr(a,mid+1,r);
    nd* c=join(a,l,mid,mid+1,r);
    for(int i=l;i<=r;i++){
        a[i]=c[i-l];
    }
    free(c);
}

int main(){
    long long int t2;
    cin>>t2;long long int t1=t2;
    while(t2--){
        long long int t,n,e;
        cin>>n;cin>>e;
        nd a[n+2];
        a[0].x=0;a[0].E=0;a[0].tot=0;a[0].y=10e9+1;a[0].f=1;

        for(long long int i=1;i<=n;i++){
            cin>>a[i].x;cin>>a[i].y;cin>>a[i].E;
            a[i].tot=0;a[i].f=1;
        }

        a[n+1].x=10e6+1;a[n+1].y=-1;a[n+1].E=0;a[n+1].tot=0;a[n+1].f=1;

        mr(a,0,n+1);
    // for(long long int i=0;i<n+1;i++){
    //     cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].E<<endl;
    // }
        for(long long int i=0;i<n+1;i++){
            for(long long int j=0;j<n+1;j++){
                int flag=0;
                if(a[i].y>=a[j].y&&i!=j){
                    if((a[i].x>a[j].x&&a[i].f==1)||(a[i].x<a[j].x&&a[i].f==0)){
                        t=a[i].tot+a[j].E-e;
                        flag=1;
                    }else{
                        t=a[i].tot+a[j].E;
                    }if(a[j].tot<t){
                        a[j].tot=t;
                        if(flag==1){
                            a[j].f=1-(a[i].f);
                        }
                    }
                }
            }
            // cout<<i<<"|"<<a[i].tot<<": ";
            // for(long long int k=0;k<n+1;k++){
            //     cout<<a[k].tot<<":"<<a[k].f<<" ";
            // }cout<<endl;
        }
        long long int max=-10e17;
        for(long long int i=0;i<n+1;i++){
            if(a[i].tot>max){
                max=a[i].tot;
            }
        }
        cout<<"Case #"<<t1-t2<<": " << max<< endl;
    }
}