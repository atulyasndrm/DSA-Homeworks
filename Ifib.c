#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long long int Ifib(long long int n){
   long long int a,b,t,i;
if(n==0){
    return 0;
}else if(n==1){
    return 1;
}else{
    a=0;b=1;
    for(i=2;i<=n;i++){
        t=b%2021;
        b=(a%2021+b%2021)%2021;
        a=t;
    }return b%2021;
}
}


long long int Rfib(long long int n){
if(n==0){
    return 0;
}else if(n==1){
    return 1;
}else{
   return (Rfib(n-1)%2021+Rfib(n-2)%2021)%2021;
}
}


long long int** mpy(long long int** a,long long int** b){
    long long int p=(((a[0][0]%2021)*(b[0][0]%2021))%2021+((a[0][1]%2021)*(b[1][0]%2021))%2021)%2021;
    long long int q=(((a[0][0]%2021)*(b[0][1]%2021))%2021+((a[0][1]%2021)*(b[1][1]%2021))%2021)%2021;
    long long int r=(((a[1][0]%2021)*(b[0][1]%2021))%2021+((a[1][1]%2021)*(b[1][1]%2021))%2021)%2021;
    a[0][0]=p%2021;a[0][1]=q%2021;a[1][0]=q%2021;a[1][1]=r%2021;
    return a;
}


long long int** Mfib(long long int** a,long long int** b,long long int n){
if(n==1){
    return a;
}
long long int **t=Mfib(a,b,n/2);
if(n%2==1&&n!=1){
    return mpy(mpy(t,t),b);
}else{
    return mpy(t,t);
}
}

int main(){
    long long int n;
    clock_t start_t, end_t;
    // scanf("%lld",&n);
    double total_t;


    // long long int* p=(long long int*)calloc(n+1,sizeof(long long int));
    // p[0]=0;
    // p[1]=1;
    long long int** a;long long int** b;
    a=(long long int**)malloc(2*sizeof(long long int*));
    a[0]=(long long int*)malloc(2*(sizeof(long long int)));a[1]=(long long int*)malloc(2*(sizeof(long long int)));
    b=(long long int**)malloc(2*sizeof(long long int*));
    b[0]=(long long int*)malloc(2*(sizeof(long long int)));b[1]=(long long int*)malloc(2*(sizeof(long long int)));

    // long long int**a=m;long long int**b=n;
    a[0][1]=1;a[0][0]=1;a[1][0]=1;a[1][1]=0;
    b[0][1]=1;b[0][0]=1;b[1][0]=1;b[1][1]=0;
    for(long long int i=420000;i<1000000000000;i+=100000){
    start_t = clock();
    printf("%lld\n",Ifib(i)%2021);
    end_t = clock();
    // printf("%lld",Ifib(n,p)%2021);
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Total time taken: %f\n", total_t );
    }
    // printf("%lld\n",(Mfib(a,b,n-1)[0][0])%2021);
    // for(int i=0;i<2;i++){
    //     for(int j=0;j<2;j++){
    //         printf("%d ",a[i][j]);
    //     }printf("\n");
    // }
    // free(p);

}