#include <stdio.h>
#include <stdlib.h>

void swap(int*a,int*b){
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int*a, int l,int r,int p){
    if(p!=l){
        swap(a+p,a+l);
    }
    int k=a[l],e=r,i=l+1;
    
    while(i<e){
        if(a[i]>k){
            swap(a+e,a+i);
            e--;
        }else{
            i++;
        }   
    }
    if(a[i]>k){
        i--;
    }
    swap(a+l,a+i);
    return i;
}
void qs(int*a,int l,int r){
    int i;
    if(l<r){
        i=partition(a,l,r,l);
        qs(a,l,i-1);
        qs(a,i+1,r);
    }
}
// int med(int* a, int l, int r){
//     // int c[r-l+1];
//     for(int i=l;i<=r;i=i+5){
//         if(a[i]<a[i+1]){
//             max=a[i];
//         }
//     }
    
// }



int select(int*a, int l, int r, int i){
    // int t=med(a,l,r);
    int t=l;
    int k= partition(a,l,r,t);
    if(k==i){
        return k;
    }else if(k<i){
        select(a,,k+1,r,i);
    }else{
        select(a,l,k-1,i);
    }


}


int main()
{
    return 0;
}