#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} nde;


nde* cn(int n){
    nde* temp=(nde*)malloc(sizeof(nde));
    temp->data=n;
    temp->next=NULL;
    return temp;
}
int pl(nde* head){
    int n=0;
    nde* temp= head;
    while(temp){
        printf("%d",temp->data);n++;
        temp=temp->next;   
    }return n;
}

int len(nde* head){
    int n=0;
    nde* temp= head;
    while(temp){
        n++;
        temp=temp->next;   
    }return n;
}

int check(nde* head,int n){
    nde* temp=head;
    while(temp){
        if(temp->data==n){
            return 1;
            break;
        }
        temp=temp->next;
    }
    return 0;
}
nde* rev(nde* head){
    nde* t1=head;
    nde* t2=head->next;
    nde* t3=t2->next;
    while(t2){
        if(t1==head){
            t1->next=NULL;
        }t2->next=t1;
        t1=t2;
        t2=t3;
        if(t3!=NULL){
        t3=t2->next;}
    }return t1;
}
// nde* recrev(nde* temp){
    
// }
void middle(nde* head){
    nde *t1=head,*t2=head;
    
    while(t2->next->next||t2->next){
        t1=t1->next;
        t2=t2->next->next;
    }
    if(t2->next->next==NULL){
        printf("%d %d",t1->data,t2->next->data);
    }else{
        printf("%d",t1->data);
    }
}
int main(){
    int c;nde* t;int flag=0;nde *head;nde* temp;
do{
scanf("%d",&c);
if(c!=-1){
    t=cn(c);
    if(flag==0){
        head=t;
        flag=1;
        temp=t;
    }
    
    temp->next=t;
    temp=temp->next;}
}while(c!=-1);
// pl(head);
head=rev(head);
pl(head);
// printf("%d",head->next->data);
middle(head);
}
