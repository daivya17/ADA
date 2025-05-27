#include<stdio.h>
#define max 9999
int n;
void prims(int graph[n][n]){
    int parent[10],vis[10],key[10];
    for(int i=0;i<n;i++){
        vis[i]=0;
        key[i] = max;
    }
    key[0] = 0;
    parent[0] = -1;
    for(int i=0;i<n-1;i++){ //findmin()
        int min=max,u = -1;
        for(int v=0;v<n;v++){
        if(vis[v] == 0 && key[v]<min){
                min = key[v];
                u = v;
            }
        }
        vis[u] = 1; //main
        for(int v=0;v<n;v++){
            if(!vis[v] && graph[u][v] && key[v]>graph[u][v]){
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    printf("Edge\tWeight\n"); //display()
    for(int i=1;i<n;i++){
        printf("%d-%d\t%d\n",parent[i],i,graph[i][parent[i]]);
    }
}
int main(){
    printf("enter no of nodes:");
    scanf("%d",&n);
    int graph[n][n];
    printf("enter adj matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    prims(graph);
    return 0;
}
