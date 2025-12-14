#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1;
int rear = -1;
void enqueue() {
    int val;
    if (rear == SIZE - 1) {
        printf("The queue is full-overflow\n");
        return;
    }
    printf("Enter element to insert: ");
    scanf("%d", &val);
    if (front == -1)   front = 0;
    rear++;
    queue[rear] = val;
    printf("Element successfully inserted\n");
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("The queue is empty-underflow\n");
        return;
    }
    printf("The element deleted is %d\n", queue[front]);
    front++;
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

void display() {
    int i;
    if (front == -1 || front > rear) {
        printf("The queue is empty-underflow\n");
        return;
    }
    printf("The elements are:\n");
    for (i = front; i <= rear; i++) {
        printf("%d\t", queue[i]);
    }
    printf("\n");
}

int main() {
    int opt;
    printf("\nOPTIONS:\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
    while (1) {
        printf("\nEnter your option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option... Try again...\n");
                break;
        }
    }
    return 0;
}

