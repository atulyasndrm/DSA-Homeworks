#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct node {
    long long int data;
    struct node* next; 
}nd;


long long int inst(char c){
    if(c=='#'){
        return 0;
    }
    else if(c=='+'){
        return 20;
    }else if(c=='-'){
        return 30;
    }else if(c=='*'){
        return 40;
    }else if(c=='/'){
        return 50;
    }else if(c=='^'){
        return 70;
    }else if(c=='('){
        return 10;
    }else if(c=='='){
        return 15;
    }
}
    
long long int out(char c){
    if(c=='+'){
        return 20;
    }else if(c=='-'){
        return 20;
    }else if(c=='*'){
        return 40;
    }else if(c=='/'){
        return 40;
    }else if(c=='^'){
        return 80;
    }else if(c=='('){
        return 100;
    }else if(c=='='){
        return 90;
    }
}

nd* cr_st(){
    return NULL;
}

nd* cr(long long int n){
    nd* t=(nd*)malloc(sizeof(nd));
    t->next = NULL;
    t->data=n;
    return t;
}

void push(nd** head,long long int n){
    nd* a=cr(n);
    if(*head==NULL){
        *head=a;
    }else{
        a->next=*head;
        *head=a;
    }
}

long long int pop(nd** head){
    nd *t=*head;
    *head=t->next;
    long long int k=t->data;
    free(t);
    return k;
}

long long int top(nd*head){
    return head->data;
}

void eval(nd** num, nd** op,nd** x,nd** y){
    long long int n2=pop(num);
    long long int o=pop(op);
    long long int n1=pop(num);long long int k=0;
    if(o==inst('+')){
        k=n1+n2;
    }
    else if(o==inst('-')){
        k=n1-n2;
    }else if(o==inst('/')){
        k=n1/n2;
    }else if(o==inst('*')){
        k=n1*n2;
    }else if(o==inst('^')){
        k=(long long int)pow(n1,n2);
    }else if(o==inst('=')){
        if(n1==1){
            push(x,n2);
        }else{
            push(y,n2);
        }
        k=n2;
    }
    push(num,k);
}


int main()
{   
    nd* o=cr_st();
    nd* num=cr_st();
    nd* x=cr_st();
    nd* y=cr_st();
    push(&x,1);
    push(&y,1);
    long long int n,flag=0;
    long long int t=-1;
    char c;
    push(&o,inst('#'));
    scanf("%lld\n",&n);
    while(n--){
        scanf("%c",&c);
        if(c<='9'&&c>='0'){
            if(t==-1){
                t++;
            }
            t=t*10+(c-'0');
        }else if(c=='x'){
            if(t!=-1){
                push(&num,t);
                t=-1;
            }
            flag=1;
        }else if(c=='y'){
            if(t!=-1){
                push(&num,t);
                t=-1;
            }flag=2;
        }
        
        else{
            if(t!=-1){
                push(&num,t);
                t=-1;
            }if(flag!=0&&c!='='){
                if(flag==1){
                    push(&num,top(x));
                }else{
                    push(&num,top(y));
                }
                flag=0;
            }
            if(c==')'){
                while(top(o)!=inst('(')){
                    eval(&num,&o,&x,&y);
                }pop(&o);
            }else if(c!='='){
                while(top(o)>=out(c)){
                    eval(&num,&o,&x,&y);
                }
                push(&o,inst(c));
            }else{
                if(flag==1){
                    push(&num,1);
                }else{
                    push(&num,2);
                }
                flag=0;
                push(&o,inst(c));
            }
        }
    }
    if(flag!=0){
        if(flag==1){
            push(&num,top(x));
        }else{
            push(&num,top(y));
        }
        flag=0;
    }
    if(t!=-1){
        push(&num,t);
        t=-1;
    }
    while(top(o)!=inst('#')){
        eval(&num,&o,&x,&y);
    }
    printf("%lld\n%lld\n%lld\n",top(x),top(y),top(num));
    
    return 0;
}