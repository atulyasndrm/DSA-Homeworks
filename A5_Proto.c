#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int comp;

void swap(double* a,double* b){
    double t=*a;
    *a=*b;
    *b=t;
}

int partition_c(double*a, int l,int r){
    double k=a[l];int e=r,i=l+1;
    while(i<e){
        comp++;
        if(a[i]>k){
            swap(a+e,a+i);
            e--;
        }else{
            i++;
        }   
    }
    if(a[i]>k){
        comp++;
        i--;
    }
    swap(a+l,a+i);
    return i;
}

double* join_c(double*a,int l1,int r1,int l2,int r2){
    double* c=(double*)malloc(sizeof(double)*(r2-l1+1));int k=0;
    while(l1<=r1&&l2<=r2){
        if(a[l1]>a[l2]){
            comp++;
            c[k]=a[l2];
            l2++;k++;
        }else{
            comp++;
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

void ms_c(double* a, int l, int r){
    if(l==r){
        return;
    }
    int mid=(l+r)/2;
    ms_c(a,l,mid);ms_c(a,mid+1,r);
    double* c=join_c(a,l,mid,mid+1,r);
    for(int i=l;i<=r;i++){
        a[i]=c[i-l];
    }
    free(c);
}


void qs_c(double*a,int l,int r){
    int i;
    if(l<r){
        i=partition_c(a,l,r);
        qs_c(a,l,i-1);
        qs_c(a,i+1,r);
    }
}

int partition(double*a, int l,int r){
    double k=a[l];int e=r,i=l+1;
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

double* join(double*a,int l1,int r1,int l2,int r2){
    double* c=(double*)malloc(sizeof(double)*(r2-l1+1));int k=0;
    while(l1<=r1&&l2<=r2){
        if(a[l1]>a[l2]){
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

void ms(double* a, int l, int r){
    if(l==r){
        return;
    }
    int mid=(l+r)/2;
    ms(a,l,mid);ms(a,mid+1,r);
    double* c=join(a,l,mid,mid+1,r);
    for(int i=l;i<=r;i++){
        a[i]=c[i-l];
    }
    free(c);
}



void qs(double*a,int l,int r){
    int i;
    if(l<r){
        i=partition(a,l,r);
        qs(a,l,i-1);
        qs(a,i+1,r);
    }
}
void ijoin(double*a,int l1,int r1,int l2,int r2,double* p2){
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
void ims(double* a, int l, int r,double* p2){
    if(l==r){
        return;
    }
    int mid=(l+r)/2;
    ims(a,l,mid,p2);ims(a,mid+1,r,p2);
    ijoin(a,l,mid,mid+1,r,p2);
    for(int i=l;i<=r;i++){
        a[i]=p2[i-l];
    }
}

void Quick_VS_Merge_Comparisons(){
    clock_t start,end;
    int n;
    // printf("Enter n: ");
    scanf("%d",&n);
    srand ( ( unsigned) time (NULL ) ) ;
for(int n=100;n<1000000+1;n=n*10){
    double* a=(double*)malloc(sizeof(double)*n);
    double* b=(double*)malloc(sizeof(double)*n);
    int max = 1000000;
    int m_c=0;int q_c=0; 
    for(int q=0;q<50;q++){
            printf(" ");
    }printf("|\n");
    
    for(int j=0;j<500;j++){
        
        for(int i=0;i<n;i++){
            double ran = ( ( double ) rand ( ) / (double ) RAND_MAX)*max;
            a[i]=ran;
            b[i]=ran;
        }

        comp=0;
        ms_c(a,0,n-1);
        m_c=m_c+comp;

        comp=0;
        qs_c(b,0,n-1);
        q_c=q_c+comp;
        if((j%10==0&&j!=0)||j==499){
            printf("#");
        }
    }
    printf("\n%d\nFinalMerge: %d counts",n,m_c/500);
    printf("FinalQuick: %d counts ",q_c/500);
    free(a); free(b); 
}

}

void Avg_RunTime_Quick(){ 
    clock_t start,end;
    
    // printf("Enter n: ");
    // scanf("%d",&n);

    srand ( ( unsigned) time (NULL ) ) ;
FILE *ptr;
    ptr=fopen("Avg_RunTime_Quick.txt","w");
    // scanf("%d",&iter);

for(int n=100000;n<1000000+1;n=n+2*(100000)){
    

    double* a=(double*)malloc(sizeof(double)*n);
    double* b=(double*)malloc(sizeof(double)*n);
    double* p2=(double*)malloc(sizeof(double)*n);
    double m_t=0, q_t=0;
    double m_time,q_time;
    int s=0;
    int iter;
    int max = 1000000;
    for(int q=0;q<50;q++){
            printf(" ");
        }printf("|\n");
    for(int j=0;j<500;j++){
        for(int i=0;i<n;i++){
            double ran = ( ( double ) rand ( ) / (double ) RAND_MAX)*max;
            a[i]=ran;
            b[i]=ran;
        }
        start=clock();
        ims(a,0,n-1,p2);
        end=clock();
        m_time=(double)(end-start);
        m_t=m_time+m_t;

        start=clock();
        qs(b,0,n-1);
        end=clock();
        q_time=(double)(end-start);
        q_t=q_time+q_t;
        if(q_t>m_t){
            s++;
            printf("Merge wins %d\n",s);
        }
        if(j%10==0||j==499){
            printf("#");
        }
        
    }
    printf("\n%d\nFinalMerge: %lf ms\n",n,m_t/500);
    printf("\n%d\nFinalQuick:%lf ms\n\n",n,q_t/500);
    fprintf(ptr,"%d\nFinalQuick:%lf ms\n\n",n,q_t/500);
    printf("Merge Wins %d Times",s);
    printf("\n");
    free(a); free(b);
}
fclose(ptr);
}

void Avg_Merge_VS_Quick(){

}

void Avg_IM_VS_Quick(){

}

void Reliability(){

}

int main()
{   
    Avg_RunTime_Quick();
    // printf("%lf",(double)CLOCKS_PER_SEC);
    
    return 0;
}