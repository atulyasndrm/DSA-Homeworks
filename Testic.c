#include <stdio.h>
#include <stdlib.h>
typedef struct node{
   int data;
   struct node* next;
} NODE;
NODE* createNode(int n){
    NODE* temp=(NODE*)malloc(sizeof(NODE));
    temp->data=n;temp->next=NULL;
    return temp;
}
void printList(NODE *n){
while(n){
    printf("%d ",n->data);
    n=n->next;
}
}
NODE* input(){
    int w; NODE  *ele,*head,*temp; int flag=0;
    do{
    scanf("%d",&w);
    if(w+1){
        ele=createNode(w);
        if(flag==0){
            head=ele;
            temp=head;flag=1;
        }else{
            temp->next=ele;
            temp=temp->next;
        }
    }
    
    }while(w!=-1);
return head;
}


NODE* solve(NODE *head){
NODE *h=head,*t,*temp1,*temp2,*prev;int flag=0;
while(h!=NULL&&h->next!=NULL){
    if(flag==0){
        temp1=head->next->next;
        head->next->next=head;
        temp2=head->next;
        head->next=temp1;
        head=temp2;
        h=head->next->next;
        prev=head->next;
        flag=1;
    }else{
        if(h->next!=NULL){
            temp1=h->next->next;
            h->next->next=h;
            temp2=h->next;
            h->next=temp1;
            h=temp2;
            prev->next=h;
            h=h->next->next;
            prev=h->next;
        }else{
            h=h->next;
        }
    }
}return head;
}


int main()
{
    NODE* head;
    head=input();
    printList((head));
    NODE*a=createNode(10);
    NODE* t=head->next;
    NODE** b=&t;
    b=&a;
    printf("\n");
    printList((head));
}
/*Do not modify the main function
 *Define the structure NODE properly
 *Write the body of the above mentioned functions*/