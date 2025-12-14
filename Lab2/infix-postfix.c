#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define SIZE 100
int stack[SIZE];
int top=-1;

void push(char c){
    if( top==SIZE-1){
       printf("Too long expression");
       return -1;
    }
    stack[++top]=c;
    return;
}
char pop(){
    if( top==-1){
       printf("Stack underflow");
       return -1;
    }
    return stack[top--];
}
 char peek(){
     if( top==-1){
       printf("Stack underflow");
       return -1;
    }
    return stack[top];
 }

 int isop(char c){
     return (c=='^' || c=='/' || c=='*' || c=='%' || c=='+' || c=='-');
 }
 int precedence(char c){
     switch(c){
         case '^':return 3;
         case '%':
         case '/':
         case '*': return 2;
         case '+':
         case '-': return 1;
         default: return 0;
     }
 }
 void infixtopostfix(char *infix,char *postfix){
     char symbol;
     int k;
     int len=strlen(infix);
     infix[len]=')';
     push('(');
     infix[len+1]='\0';
     for(int i=0;i<=len;i++){
            symbol=infix[i];
        if (symbol=='('){
                push('(');
        }else if(isalnum(symbol)){
            postfix[k++]=symbol;
        }else if(isop(symbol)){
            while(top!=0 && precedence(peek())>=precedence(symbol)){
                postfix[k++]=pop();
            }
            push(symbol);
        }else if(symbol==')'){
            while(top!=0 && peek()!='('){
                postfix[k++]=pop();
            }
            pop();
        }
     }
     postfix[k]='\0';
 }
 int main(){
     char infix[SIZE], postfix[SIZE];
     printf("Enter a valid parenthesized infix expression: ");
     scanf("%s", infix);
     infixtopostfix(infix, postfix);
     printf("Postfix Expression: %s\n", postfix);
     return 0;
 }
