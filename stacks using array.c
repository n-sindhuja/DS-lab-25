#include<stdio.h>
# define SIZE 5
int arr[SIZE];
int top=-1;
void push(){
    int val;
    if(top==SIZE-1){
        printf("The array is full-overflow");
        return;
    }
    printf("Enter element to push");
    scanf("%d",&val);
    top+=1;
    arr[top]=val;
    printf("Element successfully inserted");
    return;
}
void pop(){
    if(top==-1){
        printf("The stack is empty-underflow");
        return;
    }
    printf("the element popped is %d",arr[top]);
    top--;
    return;
}
void display(){
    if(top==-1){
        printf("The stack is empty-underflow");
        return;
    }
    printf("the elements are :\n");
    for(int i=top;i>=0;i--){
        printf("%d\t",arr[i]);
    }
}
int main(){
    int opt;
    int exiting=0;
    while(1){
        printf("\n OPTIONS:\n1.Push \n2.pop \n3.display \n4.exit ");
        printf("Enter your option:\n");
        scanf("%d",&opt);
        switch(opt){
            case 1:
            push();
            break;
            case 2:pop();
            break;
            case 3:
                display();
                break;
            case 4:printf("Exiting...");
            exiting=1;
            break;
            default:printf("Invalid option...Try again.. ");
            break;
        }
        if(exiting==1){
            break;
        }
    }
    return 0;
}