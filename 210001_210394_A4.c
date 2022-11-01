#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//NOTE: !nb = Not nearly balanced / Non nearly balancedness
//Creating the node for the Binary Search Tree(BST). 
typedef struct node{
    long long int data;
    long long int ht;
    long long int rht;
    long long int lht;
    struct node* r;
    struct node* l;
}nd;


//Initializing the BST.
nd* cr_tree(){
    return NULL;
}


//Creating a node for the BST.
nd* cr_nd(long long int n){
    nd* t=(nd*)malloc(sizeof(nd));
    t->data=n;
    t->r=NULL;
    t->l=NULL;
    t->ht=1;
    t->rht=0;
    t->lht=0;

    return t;
}


//Enumerating the BST recursively.
void pri(nd* head){
    if(head->l!=NULL){
        pri(head->l);
    }printf("%lld\n",head->data);
    if(head->r!=NULL){
        pri(head->r);
    }
}


//Global variables for the array that will store the Subtree used for its restructing. 
int alpha=0;
nd** arr;


//Recursive Function that stores the BST that has stopped being nearly balanced into an array, by storing each node in ascending order of the value it contains. 
void enumt(nd* root,nd** arr){
    if((root)==NULL){
        return;
    }
    enumt((root)->l,arr);
    arr[alpha]=(root);
    (alpha)++;
    enumt((root)->r,arr);    
}


//Function that converts the array into a perfectly balanced BST recursively
nd* reorder(nd** arr, long long int i, long long int j){
    if(i>j){
        return NULL;
    }
     long long int mid=(i+j)/2;
     nd* root=arr[mid];
     
     root->ht=j-i+1;
     root->lht=mid-i;
     root->rht=j-mid;
     root->l=reorder(arr,i,mid-1);
     root->r=reorder(arr,mid+1,j);
     return root;
}


//Function that inserts each node into the BST while maintaining its nearly balanced-ness(!nb)
void insert(nd ** head,int n){

     if(*head==NULL){//Condition for inserting an element at the start
        nd* t=cr_nd(n);
        *head=t;
        return;
    }


    else{//Intermediate insertion of element

        int flag=0;//flag to check the first point of !nb
        int q;// Variable to store the data of the node beong analyzed
        nd* a;
        nd* curr=*head;
        nd* prev=NULL;//To store the parent of the point of !nb
        nd* br_pt=NULL;//Pointer that will store the first point of !nb in the BST, at the least height
        nd* tp=NULL;


        while(curr->r!=NULL || curr->l!=NULL){
            q=curr->data;

            if(q>n){
                curr->ht++;
                curr->lht++;
                if(flag==0 && ((4*(curr->lht) > 3*(curr->ht))||(4*(curr->rht) > 3*(curr->ht)))){//Checking !nb
                    br_pt=curr;
                    tp=prev;
                    flag=1;
                }
                if(curr->l!=NULL){
                    prev=curr;
                    curr=curr->l;
               }
               else{
                    prev=curr;
                    break;
               }
            }

            else{
                curr->ht++; curr->rht++;

                if(flag==0&&(((4*(curr->lht) > 3*(curr->ht))||(4*(curr->rht) > 3*(curr->ht))))){
                   br_pt=curr;
                   tp=prev;
                   flag=1;
                }

                if(curr->r!=NULL){
                    prev=curr;
                    curr=curr->r;
                }
                else{
                    prev=curr;
                    break;
                }
            }
        }
        if(curr->data>n){
            curr->ht++;curr->lht++;
            curr->l=cr_nd(n);
        }
        else{
            curr->ht++;curr->rht++;
            curr->r=cr_nd(n);
        }

        //Rebuilding of the Subtree which stopped being nearly-balanced  
        if(br_pt!=NULL){
            arr=(nd**)malloc(sizeof(nd*)*(br_pt->ht));//Global variables initialized earlier
            alpha=0;

            enumt(br_pt,arr);//Storing the nodes of the Subtree in an array

            a=reorder(arr,0,br_pt->ht-1);//Node that stores the perfectly balanced Subtree
            
            free(arr);
            
            //Making the BST whole
            if(br_pt->data==(*head)->data){
                 *head=a;
            }
            else{
                int m=a->data;
                if(tp->data>m){
                    tp->l=a;
                }
                else{
                    tp->r=a;
                }
            }
        }
    }
    return;
}


int main(){

    nd* head=cr_tree(); //Initializing the BST
    
    long long int l=0, j, m=0, i;//l=index of the array ary(below)
    double sum=0, sum1=0, total_t;//Variables to store the time taken
    double ary[200];//Array that stores the value of the time taken from 1 to i for multiples of 50000
    FILE *filePointer ; 
    clock_t start_t, end_t,start_t1, end_t1;
       

    filePointer = fopen("210001_210394_A4.csv" , "w");//Opening the CSV file
    

//Inserting into the BST
    for(j=0;j<1;j++){//Iterations to minimize error of the data acquired
        printf("%lld",j+1);
        head=cr_tree();
        sum=0;l=0,m=0;
        for(int i=1;i<=10000000;i++){

            start_t1=clock();
            insert(&head,i);
            end_t1=clock();

            total_t = (double)(end_t1 - start_t1)/CLOCKS_PER_SEC;
            sum1=sum;
            sum=sum+total_t;

            //For the First Part
            if(i%50000==0&&j==0){
                ary[l]=sum;
                l++;
            }else if(i%50000==0&&j!=0){
                ary[l]=(sum+ary[l]);
                l++;
            }

            //For the Second Part
            if(i<=1000000&&i>=100000&&j==0){
                fprintf(filePointer,"%lld: %0.16lf\n",i,(sum-sum1)*(CLOCKS_PER_SEC));
            }
            
        }
        free(head);
    }

    fprintf(filePointer,"\n\n\n\n");//To make the CSV look neater


    for(i=0;i<200;i++){
        fprintf(filePointer,"%d: %lf\n",50000*(i+1),ary[i]/j);
    }
    // pri(head);
    fclose(filePointer);
}