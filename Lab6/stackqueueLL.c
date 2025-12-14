#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *top = NULL;
struct Node *front = NULL;
struct Node *rear = NULL;

struct Node *createNode(int val){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void push(int val){
    struct Node *newNode = createNode(val);
    newNode->next = top;
    top = newNode;
    printf("Pushed %d\n", val);
}

void pop(){
    if (top == NULL){
        printf("Stack Underflow\n");
        return;
    }
    struct Node *temp = top;
    printf("Popped %d\n", temp->data);
    top = top->next;
    free(temp);
}

void displayStack(){
    if (top == NULL){
        printf("Stack is Empty\n");
        return;
    }
    struct Node *temp = top;
    printf("Stack: ");
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void enqueue(int val){
    struct Node *newNode = createNode(val);
    if (rear == NULL){
        front = rear = newNode;
    }else{
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d\n", val);
}

void dequeue(){
    if (front == NULL){
        printf("Queue Underflow\n");
        return;
    }
    struct Node *temp = front;
    printf("Dequeued %d\n", temp->data);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

void displayQueue(){
    if (front == NULL){
        printf("Queue is Empty\n");
        return;
    }
    struct Node *temp = front;
    printf("Queue: ");
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int choice, val;
    printf("\n1. Push (Stack)\n");
    printf("2. Pop (Stack)\n");
    printf("3. Display Stack\n");
    printf("4. Enqueue (Queue)\n");
    printf("5. Dequeue (Queue)\n");
    printf("6. Display Queue\n");
    printf("7. Exit\n");
    while (1){
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            displayStack();
            break;
        case 4:
            printf("Enter value: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 5:
            dequeue();
            break;
        case 6:
            displayQueue();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
