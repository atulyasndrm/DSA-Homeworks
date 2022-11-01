#include <stdio.h>
#include <stdlib.h>

int c1=0,c2=0;//global variables to handle boundary cases.


//Note: All variables have been initialized horizontally to enable better understanding of 
// the functions by not attracting much attention to the variables themselves


// Node used for the data structure which stores the column and row of that particular 
// element or just the row number or column number in case of a head pointer 
// Rt is pointer that points to the right of the node 
// Down is a pointer that points to the down of the node
typedef struct NODE {        
    int data;
    int col,row;
    struct NODE* rt;
    struct NODE* down; 
}node;

// Function to create node, temp is just a random variable name used, and is a pointer that the stores the address of the node
node* createNode(int n,int row,int col){
    node* temp=(node*)malloc(sizeof(node));
    temp->rt=NULL; 
    temp->down=NULL;
    temp->data=n;
    temp->col=col;
    temp->row=row;
    return temp;
}

// Function to create half of the data structure
//Given any Sparse matrix, this function creates the part of the data structure that is connected only along the rows, with each row together(independently)
/* 
For example, if the given matrix is:

a11 a12 a13 0  0 ....
0   a22 0   0  0 ....
a31 0   0   0  0 ....

then this function gives us:

rh1 -> a11 -> a12 -> a13 -> NULL
rh2 -> a22 -> NULL
rh3 -> a31 -> NULL 

Where rhi(1<=i<=3) is the row head pointer for each row and they are connected vertically with rh(i-1)->down=rh(i)
*/

node* createMatrixrow(int mno){
    int  rw,  colu,  data,  mn,  no,  flag=0; 
    node   *a,  *b,  *rtemp,  *row,  *temp; 

    if(mno==1){
        scanf("%d",&mn);
        if(mn==1)c1++;
        if(mn==2)c2++;
        if(mn==0){
            return NULL;
        }
    }

        do{
        scanf("%d %d %d\n",&rw,&colu,&data);
        if(flag==0){
            b=createNode(0,rw,0);
            row=b;
            rtemp=row;
            temp=rtemp;
            flag=1;
        }
        a=createNode(data,rw,colu);

        if(rtemp->row!=rw){
            b=createNode(0,rw,0);
            rtemp->down=b;
            rtemp=rtemp->down;
            temp=rtemp; 
        }

        temp->rt=a;
        temp=temp->rt;
        scanf("%d",&mn);
        if(mn==2){
            c2++;
        }
        if(mno==1&&mn==0){
            return NULL;
        }
    }while(mno==mn);
    return row;
}

// This function is used to print the given sparse matric 
// in the increasing order of rows, and along each row 
void pri(node* row){
    node  *rowH, *rowtemp;

    rowH=row; rowtemp=row;
    while(rowH){
        rowtemp=rowH->rt;
        while(rowtemp){
            printf("%d %d %d\n",rowtemp->row,rowtemp->col,rowtemp->data);
            rowtemp=rowtemp->rt;
        }rowH=rowH->down;
    }
}

// This function is used to print the given sparse matric 
// in the increasing order of columns, and along each column 
void pricol(node *col){  
    node  *rowH,  *rowtemp;

    rowH=col; rowtemp=col;

    while(rowH){
        rowtemp=rowH->down;
        while(rowtemp){
            printf("%d %d %d\n",rowtemp->row,rowtemp->col,rowtemp->data);
            rowtemp=rowtemp->down;
        }rowH=rowH->rt;
    }
}

// This function enables connecting/linking elements along each column, very similar to what has been done for connecting along the rows.
// We first create an array of nodes, and then connect them horizontally.
// Then, we iterate over the row connected partial data structure made with createMatrixrow and connect that elements with their corresponding column.
// Finally, we free any unwanted nodes in the column head array.
// Thus, during this function, our code occupies a space of O(m)[due to the given data structure]+O(n)[due to the array]=> O(m+n) 
node* linkMat(int n,node* rowH){
    node *coltemp,  *col,  *a,  *colHtemp,  *rowHtemp,  *rowtemp,  *t,  *perm;
    int i;
    node* arr[n];

    for(i=1;i<=n;i++){
        a=createNode(0,0,i);
        arr[i-1]=a;
    }

    for(i=1;i<=n-1;i++){
        arr[i-1]->rt=arr[i];
    }

    perm=arr[0];
    colHtemp=arr[0];
    rowHtemp=rowH;
    while(rowHtemp!=NULL){
        rowtemp=rowHtemp->rt;
        while(rowtemp!=NULL){
            arr[rowtemp->col-1]->down=rowtemp;
            
            arr[rowtemp->col-1]=arr[rowtemp->col-1]->down;
            rowtemp=rowtemp->rt;
        }
        rowHtemp=rowHtemp->down;
    }
    colHtemp=perm;
    while(colHtemp->rt){
        if(colHtemp->rt->down==NULL){
            t=colHtemp->rt;
            colHtemp->rt=t->rt;
            free(t);
        }
        else{
            colHtemp=colHtemp->rt;
        }
    }
    return perm;
}


//The following function simply multiplies the given matrices, taking the input as the row head of the first matrix and the column head of the second matrix
// It multiplies the matrices in a way that is very similar to what we usually do(iterating over the columns with each row and thus getting the required row of the resulting matrix). 
node* multiply(node * row1, node * col2){
    
    node  *rowH=row1,  *rowtemp,  *a,  *b,  *rowHtemp,  *c,  *r,  *temprow, * tempcol,  *colH=col2;
    int sum,flag=0;

    while(rowH){
           colH=col2;
        while(colH){
            sum=0;
            temprow=rowH->rt;
            tempcol=colH->down;
            
            while(temprow && tempcol){
                if(temprow->col>tempcol->row){
                    tempcol=tempcol->down;
                }
                else if(temprow->col<tempcol->row){
                    temprow=temprow->rt;
                }
                else{
                    sum=sum+temprow->data*tempcol->data;
                    tempcol=tempcol->down;
                    temprow=temprow->rt;
                }
            }

            if(sum!=0){
                if(flag==0){
                    a=createNode(0,rowH->row,0);
                    rowHtemp=a;
                    rowtemp=rowHtemp;
                    r=a;
                    flag=1;
                }
                    c=createNode(sum,rowH->row,colH->col);
                if(rowtemp->row!=rowH->row){
                    a=createNode(0,rowH->row,0);
                    rowHtemp->down=a;
                    rowHtemp=rowHtemp->down;
                    rowtemp=rowHtemp;
                }
                
                rowtemp->rt=c;
                rowtemp=rowtemp->rt;
            }
            colH=colH->rt;
        }
        rowH=rowH->down;
    }
    if(flag==0){
        printf("NULL MATRIX!");
    }
    return r;
}

//MAIN
int main(){
    node *col1,*row1,*col2,*row2;int i,n;
    scanf("%d\n",&n);
    row1 = createMatrixrow(1);
    if(row1==NULL){      //For Boundary case wher both the matrices are Null Matrices.
        printf("NULL MATRIX!");
        return 0;
    }
    col1=linkMat(n,row1);
    row2=createMatrixrow(2);
    col2=linkMat(n,row2); 

    if(c1==0 || c2==0){      //Condition that enables the correct output in the boundary case where both or one of the matrices is null.
        printf("NULL MATRIX!");
    }
    else{
        node* mul=multiply(row1,col2);
        // node* mul2=linkMat(n,row2);
        // In order to link the matrices together. 
        // However,it is not required for the required output and thus has been commented out.
        pri(mul);
    }
}