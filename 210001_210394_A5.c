#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int comp;//variable used to count the number of comparisons

void swap(double* a,double* b){
    double t=*a;
    *a=*b;
    *b=t;
}//function to swap two numbers

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
}//fuction to create partition while keeping track of number of comparison

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
}//function to merge two sorted arrays into a sorted array while keeping the track of number of comparisons

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
}//funtion for merge sort while keeping track of number of comparisons


void qs_c(double*a,int l,int r){
    int i;
    if(l<r){
        i=partition_c(a,l,r);
        qs_c(a,l,i-1);
        qs_c(a,i+1,r);
    }
}//function for quick sort while keeping track of number of comparisons

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
}//function to create partition

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
}// function to merge two sorted arrays into a single sorted array

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
}//function for merge sort



void qs(double*a,int l,int r){
    int i;
    if(l<r){
        i=partition(a,l,r);
        qs(a,l,i-1);
        qs(a,i+1,r);
    }
}// function for quick sort


void ijoin(double* a,int l1,int r1,int l2,int r2,double* b){
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
    
   
} // function to join two sorted arrays into a sorted array but a improved version with less number of steps in merge sort algorithm

void ims(double* a, int l, int r,double* b){
    if(l==r){
        return;
    }
    int mid=(l+r)/2;
    ims(b,l,mid,a);ims(b,mid+1,r,a); // we are doing like this to reduce number of steps while implementing the algorithm
    ijoin(a,l,mid,mid+1,r,b);
} // the improved merge sort algorithm

void Quick_VS_Merge_Comparisons(){
    clock_t start,end;
    int n;
    srand ( ( unsigned) time (NULL ) ) ;
    FILE *ptr;
    ptr=fopen(" Quick_VS_Merge_Comparisons.csv","w");
fprintf(ptr,"n,Quick,Merge\n");
    srand ( ( unsigned) time (NULL ) ) ;
for(long long int n=100;n<1000000+1;n=n*10){
    double* a=(double*)malloc(sizeof(double)*n);
    double* b=(double*)malloc(sizeof(double)*n);
    int max = 1000000;
    long long int m_c=0;long long int q_c=0; 
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
    printf("\n%lld\nFinalMerge: %lld counts\n",n,m_c/500);
    printf("FinalQuick: %lld counts ",q_c/500);
    fprintf(ptr,"%d,%lld,%lld\n",n,m_c/500,q_c/500);
    free(a); free(b); 
}

}// function to compare the average number of comparisons of quick sort and merge sort

void Avg_RunTime_Quick(){ 
    clock_t start,end;
    
    srand ( ( unsigned) time (NULL ) ) ;
FILE *ptr;
    ptr=fopen("Avg_RunTime_Quick.csv","w");

fprintf(ptr,"n,Quick\n");
for(int n=100000;n<1000000+1;n=n+2*(100000)){
    double* b=(double*)malloc(sizeof(double)*n);
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
            b[i]=ran;
        }

        start=clock();
        qs(b,0,n-1);
        end=clock();
        q_time=(double)(end-start);
        q_t=q_time+q_t;

        if(j%10==0||j==499){
            printf("#");
        }
    }
    printf("\n%d\nFinalQuick:%lf ms\n\n",n,q_t/500);
    fprintf(ptr,"%d,%lf\n",n,(q_t*1000000/CLOCKS_PER_SEC)/500);
    printf("\n");
    free(b);
}
fclose(ptr);
} // function to determine average running time of quick sort

void Reliability(){ 
    clock_t start,end;
    
    srand ( ( unsigned) time (NULL ) ) ;
FILE *ptr;
    ptr=fopen("Reliability.csv","w");
    double time[500];
fprintf(ptr,"n,avg_Quick,5,10,20,30,50,100\n\n");
for(int n=100;n<1000000+1;n=n*10){
    double* b=(double*)malloc(sizeof(double)*n);
    double m_t=0, q_t=0;
    double m_time,q_time;
    int s=0;
    int iter;
    int max = 1000000;
    double avg;
    int e5=0,e10=0,e20=0,e30=0,e50=0,e100=0;
    for(int q=0;q<50;q++){
            printf(" ");
        }printf("|\n");
    for(int j=0;j<500;j++){
        for(int i=0;i<n;i++){
            double ran = ( ( double ) rand ( ) / (double ) RAND_MAX)*max;
            b[i]=ran;
        }

        start=clock();
        qs(b,0,n-1);
        end=clock();
        q_time=(double)(end-start);
        q_t=q_time+q_t;
        time[j]=q_time;
        if(j%10==0||j==499){
            printf("#");
        }
    }
    avg=q_t/500.0;
    
    for(int j=0;j<500;j++){
        if((double)((time[j]-avg)/avg)>0.05){
            e5++;
        }if((double)((time[j]-avg)/avg)>0.1){
            e10++;
        }if((double)((time[j]-avg)/avg)>0.2){
            e20++;
        }if((double)((time[j]-avg)/avg)>0.30){
            e30++;
        }if((double)((time[j]-avg)/avg)>0.5){
            e50++;
        }if((double)((time[j]-avg)/avg)>1){
            e100++;
        }
    }

    fprintf(ptr,"%d,%lf,%d,%d,%d,%d,%d,%d\n",n,(q_t*1000000/CLOCKS_PER_SEC)/500,e5,e10,e20,e30,e50,e100);
    
    
    free(b);
}
fclose(ptr);
} // function to analyse the reliability of quick sort


void Merge_VS_Quick_Time(){ 
    clock_t start,end;
    

    srand ( ( unsigned) time (NULL ) ) ;
FILE *ptr;
    ptr=fopen("Merge_VS_Quick_Time.csv","w");
fprintf(ptr,"n,Merge,Quick,Merge_wins\n");
for(int n=100;n<1000000+1;n=n*10){
    
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
        ms(a,0,n-1);
        end=clock();
        m_time=(double)(end-start);
        m_t=m_time+m_t;

        start=clock();
        qs(b,0,n-1);
        end=clock();
        q_time=(double)(end-start);
        q_t=q_time+q_t;
        if(q_time>m_time){
            s++;
            
        }
        if(j%10==0||j==499){
            printf("#");
        }
    }
    fprintf(ptr,"%d,%lf,%lf,%d\n",n,(m_t*1000000/CLOCKS_PER_SEC)/500,(q_t*1000000/CLOCKS_PER_SEC)/500,s);
    free(a); free(b);
}
fclose(ptr);
} // function to compare average running time of quick sort and merge sort


void Avg_IM_VS_Quick(){
clock_t start,end;
  

    srand ( ( unsigned) time (NULL ) ) ;
FILE *ptr;
    ptr=fopen("ImpMerge_VS_Quick_Time.csv","w");
fprintf(ptr,"n,ImpMerge,Quick,Merge_wins\n");
for(int n=100;n<1000000+1;n=n*10){
    
    double* a=(double*)malloc(sizeof(double)*n);
    double* b=(double*)malloc(sizeof(double)*n);
    double* c=(double*)malloc(sizeof(double)*n);
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
            c[i]=ran;
        }
        start=clock();
        ims(a,0,n-1,b);
        end=clock();
        m_time=(double)(end-start);
        m_t=m_time+m_t;

        start=clock();
        qs(c,0,n-1);
        end=clock();
        q_time=(double)(end-start);
        q_t=q_time+q_t;
        if(q_time>m_time){
            s++;
            
        }
        if(j%10==0||j==499){
            printf("#");
        }
    }
    fprintf(ptr,"%d,%lf,%lf,%d\n",n,(m_t*1000000/CLOCKS_PER_SEC)/500,(q_t*1000000/CLOCKS_PER_SEC)/500,s);
    free(a); free(b);
}
fclose(ptr);
} // function to compare average running time of improved merge sort and quick sort algorithm

void Run(){

    printf("!!Starting Avg_RunTime_Quick\n");
    Avg_RunTime_Quick();
    
    // printf("!!Quick_VS_Merge_Comparisons\n");
    // Quick_VS_Merge_Comparisons();

    // printf("!!Merge_VS_Quick_Time\n");
    // Merge_VS_Quick_Time();
    
    // printf("!!Reliability\n");
    // Reliability();

    // printf("!!Avg_IM_VS_Quick\n");
    // Avg_IM_VS_Quick();
}
// function for all type of analysis


int main()
{   
    Run();
    return 0;
} // main function