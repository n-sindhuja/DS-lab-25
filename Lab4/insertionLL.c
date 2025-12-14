#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void createList(int arr[], int n){
    if (n == 0)
        return;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = NULL;
    struct Node *temp = head;
    for (int i = 1; i < n; i++){
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }
    printf("Linked list created from array.\n");
}

void insertAtBeginning(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("%d inserted at the beginning.\n", data);
}

void insertAtEnd(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else{
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("%d inserted at the end.\n", data);
}

void insertAtPosition(int data, int position){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (position < 1){
        printf("Invalid position!\n");
        free(newNode);
        return;
    }
    if (position == 1){
        newNode->next = head;
        head = newNode;
        printf("%d inserted at position %d.\n", data, position);
        return;
    }
    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL){
        printf("Position out of range!\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d inserted at position %d.\n", data, position);
}

void displayList(){
    struct Node *temp = head;
    if (temp == NULL){
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    int choice, data, pos, n, arr[100];
    while (1){
        printf("\n--- Options ---\n");
        printf("1. Create list from array\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            printf("Enter number of elements: ");
            scanf("%d", &n);
            printf("Enter %d elements: ", n);
            for (int i = 0; i < n; i++)
                scanf("%d", &arr[i]);
            createList(arr, n);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 4:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertAtPosition(data, pos);
            break;
        case 5:
            displayList();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

