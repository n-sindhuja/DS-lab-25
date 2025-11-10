#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head=NULL;

void createListFromUserInput() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid size.\n");
        return;
    }

    int *arr = (int*)malloc(size * sizeof(int));
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Clear old list if it exists
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    struct Node* current = NULL;
    for (int i = 0; i < size; i++) {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = arr[i];
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            current = head;
        } else {
            current->next = newnode;
            current = newnode;
        }
    }

    free(arr);
    printf("Linked list created successfully!\n");
}

void deletebeg(){
    if(head==NULL){
        printf("Linked List is empty");
        return;
    }
    struct Node* temp=head;
    head=head->next;
    printf("Deleted %d from beginning",temp->data);
    temp->next=NULL;
    free(temp);
}

void deleteend(){
    if (head==NULL){
        printf("Linked List is empty");
        return;
    }
    if (head->next==NULL){
        printf("Deleted %d from beginning",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node* temp=head;
    struct Node* prev=NULL;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    printf("Deleted %d from end",temp->data);
    prev->next=NULL;
    free(temp);
}

void deletepos(int pos){
    if (head==NULL){
        printf("Linked List is empty");
        return;
    }
    if (pos<=0){
        printf("Invalid position");
        return;
    }
    if (pos == 1) {
        deletebeg();
    }
    struct Node* temp=head;
    struct Node* prev=NULL;

    for(int i=0;i<pos-1 && temp!=NULL;i++){
        prev=temp;
        temp=temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    prev->next=temp->next;
    printf("Deleted %d from %d",temp->data,pos);
    temp->next=NULL;
    free(temp);
}

void display(){
    struct Node* temp=head;
    if (head==NULL){
        printf("Linked List is empty");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, pos;
    printf("\n--- Linked List Operations ---\n");
    printf("1. Create LL from array\n");
    printf("2. Delete from Beginning\n");
    printf("3. Delete from End\n");
    printf("4. Delete by Position\n");
    printf("5. Display\n");
    printf("6. Exit\n");
    
    while (1) {
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            createListFromUserInput();
            break;

    case 2:
    deletebeg();
    break;
    case 3:
    deleteend();
    break;
    case 4:
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    deletepos(pos);
    break;
    case 5:
    display();
    break;
    case 6:
    exit(0);    
    
    
    default:
        printf("Invalid choice. Try again.\n");
        }
    }
        return 0;
    }
