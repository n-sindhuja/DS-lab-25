#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

struct Node *createListFromArray(int arr[], int n){
    if (n == 0)
        return NULL;
    struct Node *head = NULL, *temp = NULL;
    for (int i = 0; i < n; i++){
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;
        temp = newNode;
    }
    return head;
}

void printList(struct Node *head){
    while (head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void sortList(struct Node *head){
    if (head == NULL)  return;
    struct Node *i, *j;
    int temp;
    for (i = head; i->next != NULL; i = i->next)
        for (j = i->next; j != NULL; j = j->next)
            if (i->data > j->data){
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
}

struct Node *concatenate(struct Node *head1, struct Node *head2){
    if (head1 == NULL) return head2;
    if (head2 == NULL)  return head1;
    struct Node *temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    return head1;
}

struct Node *reverseList(struct Node *head){
    struct Node *prev = NULL, *curr = head, *nextNode = NULL;
    while (curr != NULL){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

int main(){
    int n1, n2;
    printf("Enter number of elements for List 1: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter %d elements:\n", n1);
    for (int i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);
    struct Node *list1 = createListFromArray(arr1, n1);
    printf("\nEnter number of elements for List 2: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter %d elements:\n", n2);
    for (int i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);
    struct Node *list2 = createListFromArray(arr2, n2);
    printf("\nList 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);
    sortList(list1);
    sortList(list2);
    printf("\nSorted List 1: ");
    printList(list1);
    printf("Sorted List 2: ");
    printList(list2);
    struct Node *joined = concatenate(list1, list2);
    printf("\nConcatenated List: ");
    printList(joined);
    joined = reverseList(joined);
    printf("Reversed Concatenated List: ");
    printList(joined);
    return 0;
}
