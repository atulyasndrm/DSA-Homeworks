#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
void join(double*a,int l1,int r1,int l2,int r2,int n){
    //double* c=(double*)malloc(sizeof(double)*(r2-l1+1));
    int k=n;
    while(l1<=r1&&l2<=r2){
        if(a[l1]>a[l2]){
            a[k]=a[l2];
            l2++;k++;
        }else{
            a[k]=a[l1];
            l1++;k++;
        }
    }
    while(l1<=r1){
        a[k]=a[l1];
        l1++;k++;
    }
    while(l2<=r2){
        a[k]=a[l2];
        l2++;k++;
    }
    //return c;
}

void ms(double* a, int l, int r,int n){
    if(l==r){
        return;
    }
    int mid=(l+r)/2;
    ms(a,l,mid,n);ms(a,mid+1,r,n);
    join(a,l,mid,mid+1,r,n);
    for(int i=l;i<=r;i++){
        a[i]=a[n+i-l];
    }
    //free(c);
}
int main(){
    int n;
    //printf("Enter n: ");
    scanf("%d",&n);

    double* a=(double*)malloc(sizeof(double)*(2*n));
    //double* b=(double*)malloc(sizeof(double)*n);
    int max = 1000;
    //int m_c=0;int q_c=0; 
    
    srand ( ( unsigned) time (NULL ) ) ;

    double m_t=0;
    clock_t sat,end;
for(int j=0;j<1;j++){
    //printf("HI\n");
    for(int i=0;i<n;i++){
        double ran = ( ( double ) rand ( ) / (double ) RAND_MAX)*max;
        a[i]=ran;
        //b[i]=ran;
       
    }
    double mt;
    sat=clock();
    ms(a,0,n-1,n);
    end=clock();
    // for(int y=0;y<n;y++){
    //     printf("%lf\n",*(a+y));
    // }
    mt=end-sat;
    m_t+=mt;
}
printf("imerge 2: %lf\n",m_t);
}