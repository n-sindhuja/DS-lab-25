#include<stdio.h>
#include<stdlib.h>
#define MAX 20
struct Node{
    int vertex;
    struct Node* next;
};
struct Node* adj[MAX];
int visited[MAX];
void addEdge(int u,int v){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->vertex=v;
    newNode->next=adj[u];
    adj[u]=newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->vertex=u;
    newNode->next=adj[v];
    adj[v]=newNode;
}
void DFS(int node){
    visited[node]=1;
    struct Node* temp=adj[node];
    while(temp!=NULL){
        if(!visited[temp->vertex]){
            DFS(temp->vertex);
        }
        temp=temp->next;
    }
}
int main(){
    int n,e,u,v;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&e);
    for(int i=0;i<n;i++)
        adj[i] = NULL;
    printf("Enter edges (u v):\n");
    for(int i=0;i<e;i++) {
        scanf("%d %d",&u,&v);
        addEdge(u,v);
    }
    for(int i=0;i<n;i++)
        visited[i]=0;
    DFS(0);
    int connected=1;
    for (int i=0;i<n;i++) {
        if (!visited[i]) {
            connected=0;
            break;
        }
    }
    if (connected)
        printf("The graph is CONNECTED.\n");
    else
        printf("The graph is NOT connected.\n");
    return 0;
}
