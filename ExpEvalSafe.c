#include <stdio.h>
#include <stdlib.h>


//Function to calculate the power of the two numbers
int power(int n1,int n2){
    int x=1;
    for(int i=1;i<=n2;i++){
        x=x*n1;
    }
    return x;
}


//In-stack priority of the operators 
int isp(char c){
    if(c=='+'){
     return 2;
    }
    else if(c=='-'){
        return 1;
    }
  else if(c=='*'){
     return 4;
    }
    else if(c=='/'){
        return 3;
    }
    else if(c=='^'){
     return 5;
    }
    else if(c=='('){
        return 0;
    }
    else {
        return -10;
    }
}


//Out-stack priority of the operators 
int osp(char c){
    if(c=='+'){
        return 1;
    }
    else if(c=='-'){
        return 2;
    }
    else if(c=='*'){
        return 3;
    }
    else if(c=='/'){
        return 4;
    }
     else if(c=='^'){
        return 6;
     }
     else if(c=='('){
        return 7;
     }
     else {
        return -10;
     }
}


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
    if((*head)!=NULL){
        temp->next=(*head);
        (*head)=temp;
    }else{
        (*head)=temp;
    }
}


//Popping data out of the stack
void  pop(node** head){
        node* temp= *head;
        (*head)=(*head)->next;
        free(temp);
        
}


//Returns the value at the head of the stack
int front(node* head){
   return head->data;
}


// n = Length of the string being given.

// res- result of the operation being evaluated.

//n1 and n2 are variables that hold the values that are being calculated.

//op = operator value to identify the operator

//num is the numerical digit being accepted

int main(){

    //Initializations
    int   n,  res,  n1,  n2,  op,  num=0;
    char c;
    node * head_num=cr_st();
    node * head_op=cr_st();

    scanf("%d\n",&n);
    
    push(&head_op,-10);//Equivalent of the $ symbol used in class
    
    while(n){

        
        //Condition to calculate numbers >9
        scanf("%c",&c);
        if('0' <= c && c <= '9'){
            num=num*10+c-'0';
        }
        

        //Condition for Parentheses
        else if(c==')'){
        
            if(num!=0){
                push(&head_num,num);
                num=0;
            }    
            while(front(head_op)!=0){
                n2=front(head_num);
                pop(&head_num);
                n1=front(head_num);
                pop(&head_num);
                op=front(head_op);
                if(op==1){
                    res=n1-n2;
                }
                else if(op==2){
                    res=n1+n2;
                }
                else if(op==3){
                    res=n1/n2;
                }
                else if(op==4){
                    res=n1*n2;
                }
                else if(op==5){
                    res=power(n1,n2);
                }
                push(&head_num,res);
                pop(&head_op);
            }
            pop(&head_op);
        }


        //Condition for evaluating the operator
        else{
            if(num!=0){
                push(&head_num,num);
                num=0;
            }
            while(front(head_op)>=osp(c)){
                n2=front(head_num);
                pop(&head_num);
                n1=front(head_num);
                pop(&head_num);
                op=front(head_op);
                if(op==1){
                    res=n1-n2;
                }
                else if(op==2){
                    res=n1+n2;
                }
                else if(op==3){
                    res=n1/n2;
                }
                else if(op==4){
                    res=n1*n2;
                }
                else if(op==5){
                    res=power(n1,n2);
                }
                push(&head_num,res);
                pop(&head_op);
            }
            push(&head_op,isp(c));
       }
       n--;//Used for scanning the string
    }
    
    if(num!=0){
        push(&head_num,num);
        num=0;
    }

    //To deal with the values remaining in the stack after scanning over the stack
    while(front(head_op)!=-10){
        n2=front(head_num);
        pop(&head_num);
        n1=front(head_num);
        pop(&head_num);
        op=front(head_op);
        
        if(op==1){
            res=n1-n2;
        }
        else if(op==2){
            res=n1+n2;
        }
        else if(op==3){
            res=n1/n2;
        }
        else if(op==4){
            res=n1*n2;
        }
        else if(op==5){
            res=power(n1,n2);
        }
        push(&head_num,res);
        pop(&head_op);
    }
    printf("%d",front(head_num));
        
}