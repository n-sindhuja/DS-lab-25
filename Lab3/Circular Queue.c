#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1;
int rear = -1;
void enqueue() {
    int val;
    if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front) {
        printf("The queue is full-overflow\n");
        return;
    }
    printf("Enter element to insert: ");
    scanf("%d", &val);
    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = val;
    printf("Element successfully inserted\n");
}

void dequeue() {
    if (front == -1) {
        printf("The queue is empty-underflow\n");
        return;
    }
    printf("The element deleted is %d\n", queue[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    return;
}

void display() {
    int i;
    if (front == -1) {
        printf("The queue is empty-underflow\n");
        return;
    }
    printf("The elements are:\n");
    i = front;
    while (1) {
        printf("%d\t", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
int main() {
    int opt;
    printf("\n OPTIONS:\n1.Insert \n2.Delete \n3.display \n4.exit ");
    while (1) {
        printf("\nEnter your option:\n");
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
                printf("Exiting...");
                return 0;
            default:
                printf("Invalid option...Try again...");
                break;
        }
    }
    return 0;
}
