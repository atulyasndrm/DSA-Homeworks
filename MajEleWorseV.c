#include <stdio.h>
#include <stdlib.h>
int len=0;
typedef struct nd{
    int data;
    struct nd* next;
}node;


node* cr_node(int n){
    node* temp = (node*)malloc(sizeof(node));
    temp->data=n; temp->next=NULL;
    return temp;
}

node* cr_st(){
    return NULL;
}

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

void  pop(node** head){
    if((*head)!=NULL){
        node* temp= *head;
        int t= temp->data;
        (*head)=(*head)->next;
        free(temp);
        len--;
        // printf("%d\n",t);
        // return t;
    }
    else{
        printf("!\n");
        // return;
    }
   
}

void  front(node* head){
if(head!=NULL){
   printf("%d\n",head->data);
}else{
    printf("!\n");
}
}

int main(){
node* head= cr_st();
int n,val,i,t;
scanf("%d",&t);
int a[t];
// for(i=0;i<t;i++){
//     scanf("%d\n",&n);
//     if(n==0){
//         scanf("%d\n",&val);
//         push(&head,val);
//     }else if(n==1){
//         pop(&head);
//     }else if(n==2){
//         front(head);
//     }else{
//         printf("%d\n",len);
//     }
// }
for(i=0;i<t;i++){
    scanf("%d",a+i);
}
for(i=0;i<t;i++){
    if(i==0||head==NULL){
        push(&head,a[i]);
    }else{
        if(a[i]!=head->data){
            pop(&head);
        }else{
            push(&head,a[i]);
        }
    }
}
if(head==NULL){
    printf("NO");
}else{
    printf("YES,%d",head->data);
}
}