#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>



void join(double*a,int l1,int r1,int l2,int r2,double* p2){
    // double* c=(double*)malloc(sizeof(double)*(r2-l1+1));
    int k=0;
    while(l1<=r1&&l2<=r2){
        if(a[l1]>a[l2]){
            p2[k]=a[l2];
            l2++;k++;
        }else{
            p2[k]=a[l1];
            l1++;k++;
        }
    }
    while(l1<=r1){
        p2[k]=a[l1];
        l1++;k++;
    }
    while(l2<=r2){
        p2[k]=a[l2];
        l2++;k++;
    }
}

void ms(double* a, int l, int r,double* p2){
    if(l==r){
        return;
    }
    int mid=(l+r)/2;
    ms(a,l,mid,p2);ms(a,mid+1,r,p2);
    join(a,l,mid,mid+1,r,p2);
    for(int i=l;i<=r;i++){
        a[i]=p2[i-l];
    }
}




int main()
{   
    clock_t start,end;
    int n=100000;

    double* p2=(double*)malloc(sizeof(double)*n);
    double* a=(double*)malloc(sizeof(double)*n);
    double* b=(double*)malloc(sizeof(double)*n);

    double m_t=0, q_t=0;
    double m_time,q_time;
    int max = 100000;
    
    srand ( ( unsigned) time (NULL ) ) ;


    for(int i=0;i<n;i++){
        double ran = ( ( double ) rand ( ) / (double ) RAND_MAX)*max;
        a[i]=ran;
        b[i]=ran;
    }
// for(int i=0;i<n;i++){
//         printf("%lf ",a[i]);
//     }
    start=clock();
    ms(a,0,n-1,p2);
    end=clock();
    m_time=(double)(end-start);
    m_t=m_time+m_t;

    printf("IMerge: %lf\n",m_t);
    // for(int i=0;i<n;i++){
    //     printf("%lf\n",a[i]);
    // }
    // printf("%lf",(double)CLOCKS_PER_SEC);
    free(a); free(b);
    return 0;
}