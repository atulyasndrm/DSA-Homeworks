#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
int flag=0;
//double * b=(double*)malloc(n*sizeof(double));
void join(double* a,int l1,int r1,int l2,int r2,double* b){
    //double* c=(double*)malloc(sizeof(double)*(r2-l1+1));
    int k=l1;
    
    while(l1<=r1&&l2<=r2){
        if(a[l1]>a[l2]){
            b[k]=a[l2];
            l2++;k++;
        }else{
            b[k]=a[l1];
            l1++;k++;
        }
    }
    while(l1<=r1){
        b[k]=a[l1];
        l1++;k++;
    }
    while(l2<=r2){
        b[k]=a[l2];
        l2++;k++;
    }
    
    //return c;
}

void ms(double* a, int l, int r,double* b){
    if(l==r){
        return;
    }
    int mid=(l+r)/2;
    ms(b,l,mid,a);ms(b,mid+1,r,a);
    join(a,l,mid,mid+1,r,b);
    // for(int i=l;i<=r;i++){
    //     a[i]=b[i-l];
    // }
    //free(c);
}

int main()
{   
    clock_t start,end;
    int n=100000;
    

    double* a=(double*)malloc(sizeof(double)*n);
    double* b=(double*)malloc(sizeof(double)*n);

    double m_t=0;
    double m_time;

    
    int max = 1000000;
    //int m_c=0;int q_c=0; 
    
    srand ( ( unsigned) time (NULL ) ) ;


for(int j=0;j<500;j++){
    // printf("HI\n");
    for(int i=0;i<n;i++){
        double ran = ( ( double ) rand ( ) / (double ) RAND_MAX)*max;
        a[i]=ran;
        b[i]=ran;
    }
    start=clock();
    ms(a,0,n-1,b);

    // for(int i=0;i<n;i++){
    //     a[i]=b[i];
    // }
    end=clock();
    // for(int i=0;i<n;i++){
    //    printf("%lf\n",b[i]);
    // }
    m_time=(double)(end-start);
    m_t=m_time+m_t;

    //printf("iiMerge:%lf\n",m_t);
}
    printf("\niiFinalMerge:%lf\n",(m_t*1000000/CLOCKS_PER_SEC)/500);
    // printf("%lf",(double)CLOCKS_PER_SEC);
    free(a); free(b);
    return 0;
}