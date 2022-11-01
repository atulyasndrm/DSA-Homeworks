#include <stdio.h>
#include <stdlib.h>
int len=0;//Variable for the length of the stack


//Node used for implementing stack through linked lists
typedef struct nd{
    int data;
    struct nd* next;
}node;


//Creating node for the stack
node* cr_node(int n){
    node* temp = (node*)malloc(sizeof(node));
    temp->data=n; temp->next=NULL;
    return temp;
}


//Initializing the stack
node* cr_st(){
    return NULL;
}


//Pushing data into the stack
void push(node** head,int n){
    node* temp=cr_node(n);
// if((*head)!=NULL){
    temp->next=(*head);
    (*head)=temp;
// }else{
//     (*head)=temp;
// }
len++;
}


//Popping data out of the stack 
void  pop(node** head){
    if((*head)!=NULL){
        node* temp= *head;
        int t= temp->data;
        (*head)=(*head)->next;
        free(temp);
        len--;
        printf("%d\n",t);
        // return t;
    }
    else{
        printf("!\n");
        // return;
    }
   
}


//Returns the value at the head of the stack
void  front(node* head){
if(head!=NULL){
   printf("%d\n",head->data);
}else{
    printf("!\n");
}
}


int main(){
//Managing the queries
//Number of queries = t
//val = number to be pushed
node* head= cr_st();
int n,val,i,t;
scanf("%d",&t);
for(i=0;i<t;i++){
    scanf("%d\n",&n);
    if(n==0){
        scanf("%d\n",&val);
        push(&head,val);
    }else if(n==1){
        pop(&head);
    }else if(n==2){
        front(head);
    }else{
        printf("%d\n",len);
    }
}
scanf("%d",&n);
}