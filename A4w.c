#include <stdio.h>
#include <stdlib.h>
#include<time.h>
typedef struct node{
    int data;
    int ht;
     int rht;
    int lht;
    struct node* r;
    struct node* l;
}nd;

nd* cr_tree(){
    return NULL;
}

nd* cr_nd( int n){
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
    }printf("%d\n",head->data);
    if(head->r!=NULL){
        pri(head->r);
    }
}

int alpha=0;
nd** arr;

 nd* reorder(nd** arr, int i, int j){
    if(i>j){
        return NULL;
    }
     int mid=(i+j)/2;
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

void insert(nd** head, int n){
    // printf("%d\n",n);
    if(*head==NULL){
        nd* t=cr_nd(n);
        *head=t;
        return;
    }
    else{
         int flag=0; int q;
        nd *curr=*head ;
        nd *tension=NULL;
        while((curr->r!=NULL || curr->l!=NULL)){
            q=curr->data;
            if(q>n){
               curr->ht++;curr->lht++;
               if(flag==0&&((4*(curr->lht) > 3*(curr->ht))||(4*(curr->rht) > 3*(curr->ht)))){
                   //printf("%d %d %d %d&\n",tension->data,tension->ht,tension->lht,tension->rht);
                        
                        tension=curr;
                        flag=1;
               }
               if(curr->l!=NULL){
                curr=curr->l;
               }else{
                    break;
               }
            }
            else{
                curr->ht++; curr->rht++;

                if(flag==0&&(((4*(curr->lht) > 3*(curr->ht))||(4*(curr->rht) > 3*(curr->ht))))){
                
                   tension=curr;
                //    printf("%d %d %d %d@\n",tension->data,tension->ht,tension->lht,tension->rht);
                   flag=1;
                }
                if(curr->r!=NULL){
                    curr=curr->r;
                }else{
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
            nd* d;
            int aa=tension->data;
            int fld=1;
            nd* tem=*head;
            while(fld){
                if(aa==tem->data){
                    fld=0;
                }
               else if(aa>tem->data){
                   if(tem->r!=NULL && aa==tem->r->data){
                       fld=0;
                       d=tem;
                       tem->r=NULL;
                   }
                   else{
                       tem=tem->r;
                   }
               }
               else if(aa<tem->data){
                   if(tem->l!=NULL && aa==tem->l->data){
                       fld=0;
                       d=tem;
                       tem->l=NULL;
                   }
                   else{
                       tem=tem->l;
                   }
               }
            }
            int flg=0;
            arr=(nd**)malloc(sizeof(nd*)*(tension->ht));
            alpha=0;
            enumt(tension,arr);
            
            nd* a=reorder(arr,0,tension->ht-1);
            free(arr);
        if(tension->data==(*head)->data){
            *head=a;
        }
        else{
            if(d->r==NULL){
                d->r=a;
            }
            else if(d->l==NULL){
                d->l=a;
            }
        }
        }
        return;
    }   
    //pri(*head);
    // printf("\n");
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


    start_t1 = clock();
    // for(i=0;i<iter;i++){
    //     printf("%lld: %lf\n",i+1,a[i]);
    // }
    end_t1 = clock();
    printf("%lf\n",total_t1/ CLOCKS_PER_SEC);
    printf("%lf",(double)(end_t1 - start_t1)/ CLOCKS_PER_SEC);

}