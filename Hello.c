#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int x;
    int y;
    int E;
    int c;
} nd;
int main(){
    int t;
    scanf("%d",&t);
   while(t--){
        int n; scanf("%d",&n);
        nd a[n+1][n+1];
        for(int j=0;j<n;j++){
            scanf("%d",&(a[0][j].x));
        
            scanf("%d",&(a[0][j].y));
    
            scanf("%d",&(a[0][j].E));
        }
        for(int j=0;j<n;j++)
        {
            a[j][0]=a[0][j];
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(i<=j)
                {
                    a[i][j].c=1;
                }
                else
                {
                    a[i][j].c=0;
                }
            }
        }
        for( int i=1 ; i<n+1 ; i++)
        {
            nd curr = a[i];
            
        }


    

    }
}


