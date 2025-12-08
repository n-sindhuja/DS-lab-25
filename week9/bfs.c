#include <stdio.h>
#include <stdlib.h>
#define MAX 20
struct Node {
    int vertex;
    struct Node* next;
};
struct Node* adj[MAX]; 
int visited[MAX];
void addEdge(int u,int v) {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->vertex=v;
    newNode->next=adj[u];
    adj[u]=newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->vertex=u;
    newNode->next=adj[v];
    adj[v]=newNode;
}
int queue[MAX],front=0,rear=0;
void enqueue(int v){
    queue[rear++]=v;
}
int dequeue(){
    return queue[front++];
}
void BFS(int start){
    for(int i=0;i<MAX;i++)
        visited[i]=0;
    enqueue(start);
    visited[start]=1;
    printf("BFS Traversal: ");
    while (front<rear) {
        int node=dequeue();
        printf("%d ",node);
        struct Node* temp=adj[node];
        while (temp!=NULL) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex]=1;
                enqueue(temp->vertex);
            }
            temp=temp->next;
        }
    }
    printf("\n");
}
int main() {
    int n,e,u,v,start;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&e);
    for(int i=0;i<n;i++)
        adj[i]=NULL;
    printf("Enter edges (u v):\n");
    for (int i=0;i<e;i++) {
        scanf("%d %d",&u,&v);
        addEdge(u,v);
    }
    printf("Enter start vertex: ");
    scanf("%d",&start);
    BFS(start);
    return 0;
}
