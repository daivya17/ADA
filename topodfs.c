#include<stdio.h>
#define max 100
int stack[100],n;
int top = -1;
void push(int x){
    stack[++top] = x;
}
int pop(){
    return stack[top--];
}
int isempty(){
    return top==-1;
}
void dfs(int graph[max][max],int vis[],int u){
    vis[u] = 1;
    for(int v=0;v<n;v++){
        if(!vis[v] && graph[u][v]){
            dfs(graph,vis,v);
        }
    }
    push(u);
}
void toposort(int graph[max][max]){
    int vis[max];
    for(int i=0;i<n;i++){
        vis[i] = 0;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(graph,vis,i);
        }
    }
    printf("topological order:");
    while(!isempty()){
        printf("%d ",pop());
    }
    printf("\n");
}
int main(){
    printf("enetr no of vertices:");
    scanf("%d",&n);
    printf("enter adjacency matrix:\n");
    int graph[max][max];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    toposort(graph);
    return 0;
}
