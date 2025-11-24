#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void createDLLFromArray(int arr[], int n) {
    if (n == 0) return;
    head = createNode(arr[0]);
    struct Node* temp = head;
    for (int i = 1; i < n; i++) {
        struct Node* newNode = createNode(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }
}
void insertLeft(int target, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = head;
    if (head == NULL) {
        printf("List is empty. Cannot insert.\n");
        free(newNode);
        return;
    }
    while (current != NULL && current->data != target) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with value %d not found.\n", target);
        free(newNode);
        return;
    }
    newNode->next = current;
    newNode->prev = current->prev;
    if (current->prev != NULL)
        current->prev->next = newNode;
    else
        head = newNode; 
    current->prev = newNode;
}
void deleteNode(int value) {
    struct Node* current = head;
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    while (current != NULL && current->data != value) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }
    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        head = current->next; 
    if (current->next != NULL)
        current->next->prev = current->prev;
    free(current);
    printf("Node with value %d deleted.\n", value);
}
void display() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("DLL: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    createDLLFromArray(arr, n);
    printf("Doubly Linked List created:\n");
    display();
    int choice, value, target;
    while (1) {
        printf("\nMENU:\n");
        printf("1. Insert Left\n");
        printf("2. Delete Value\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter target value to insert left of: ");
                scanf("%d", &target);
                insertLeft(target, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
