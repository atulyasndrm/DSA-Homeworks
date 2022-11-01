#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct node{
    long long int data;
    long long int ht;
    long long int rht;
    long long int lht;
    struct node* r;
    struct node* l;
}nd;
nd* cr_tree(){
    return NULL;
}
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
void pri(nd* head){
    if(head->l!=NULL){
        pri(head->l);
    }printf("%lld\n",head->data);
    if(head->r!=NULL){
        pri(head->r);
    }
}
int alpha=0;
nd** arr;
nd* reorder(nd** arr, long long int i, long long int j){
    if(i>j){
        return NULL;
    }
     long long int mid=(i+j)/2;
     nd* root=arr[mid];
     //printf("%d\n",root->data);
     root->ht=j-i+1;
     root->lht=mid-i;
     root->rht=j-mid;
     root->l=reorder(arr,i,mid-1);
     root->r=reorder(arr,mid+1,j);
     return root;
}
void enumt(nd* root,nd** arr){
    if((root)==NULL){
        return;
    }
    enumt((root)->l,arr);
    arr[alpha]=(root);
    (alpha)++;
    enumt((root)->r,arr);    
}
void insert(nd ** head,int n){
    //  printf("%lld\n",n);
     if(*head==NULL){
        nd* t=cr_nd(n);
        *head=t;
        return;
    }
    else{
        int flag=0;
        int q;
        nd* curr=*head;
        nd* prev=NULL;
        nd* tension=NULL;
        nd* tp=NULL;
        while(curr->r!=NULL || curr->l!=NULL){
            q=curr->data;
            if(q>n){
                curr->ht++;
                curr->lht++;
                if(flag==0 && ((4*(curr->lht) > 3*(curr->ht))||(4*(curr->rht) > 3*(curr->ht)))){
                    tension=curr;
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
                // printf("%d\n",curr->ht);
                if(flag==0&&(((4*(curr->lht) > 3*(curr->ht))||(4*(curr->rht) > 3*(curr->ht))))){
                
                   tension=curr;
                   tp=prev;
                //    printf("%lld %lld %lld %lld@\n",tension->data,tension->ht,tension->lht,tension->rht);
                   flag=1;
                }
                if(curr->r!=NULL){
                    prev=curr;
                    curr=curr->r;
                }else{
                    prev=curr;
                    break;
                }
            }
        }
        if(curr->data>n){
            curr->ht++;curr->lht++;
            curr->l=cr_nd(n);
        }else{
            curr->ht++;curr->rht++;
            curr->r=cr_nd(n);
        }

        if(tension!=NULL){
            arr=(nd**)malloc(sizeof(nd*)*(tension->ht));
            alpha=0;
            enumt(tension,arr);
            nd* a=reorder(arr,0,tension->ht-1);
            free(arr);
            if(tension->data==(*head)->data){
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
        nd* head=cr_tree();
    clock_t start_t, end_t,start_t1, end_t1;
    double total_t,total_t1;
    long long int iter=1000000;
    double a[1000000];
    long long int i;
  start_t1 = clock();
    for(i=1;i<iter+1;i++){
        start_t = clock();
        insert(&head,i);
        end_t = clock();
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
        a[i-1]=total_t;
        // printf("%lld: %lf\n",i,total_t);
        // printf("->%d %d %d %d %d\n",head->data,head->ht,head->lht,head->rht,i);
        // printf("------------\n");
    }
    end_t1 = clock();
    total_t1=(double)(end_t1 - start_t1);


    // start_t1 = clock();
    // // for(i=0;i<iter;i++){
    // //     printf("%lld: %lf\n",i+1,a[i]);
    // // }
    // end_t1 = clock();
    printf("%lf\n",total_t1/ CLOCKS_PER_SEC);
    printf("%lf",(double)(end_t1 - start_t1)/ CLOCKS_PER_SEC);

}