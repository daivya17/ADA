#include<stdio.h>
#define max 100
int adj[max][max];
int indeg[max];
int topo[max];
int vertices;
void init(int v){
    vertices = v;
    for(int i=0;i<v;i++){
        indeg[i] = 0;
        for(int j=0;j<v;j++){
            adj[i][j] = 0;
        }
    }
}
void addedge(int u,int v){
    adj[u][v] = 1;
    indeg[v]++;
}
void topologicalsort(){
    int q[max];
    int front = 0,rear = 0;
    int index = 0;

    for(int i=0;i<vertices;i++){
        if(indeg[i] == 0){
            q[rear++] = i;
        }
    }
    while(front != rear){
        int u = q[front++];
        topo[index++] = u;
        for(int i=0;i<vertices;i++){
            if(adj[u][i] == 1){
                indeg[i]--;
                if(indeg[i] == 0){
                    q[rear++] = i;
                }
            }
        }
    }
    if(index != vertices){
        printf("Topological sort not possible\n");
        return;
    }
    printf("Topological order:");
    for(int i=0;i<vertices;i++){
        printf("%d ",topo[i]);
    }
    printf("\n");
}
int main(){
    int v,u,w,e;
    printf("enter no of vertices:");
    scanf("%d",&v);
    init(v);

    printf("enter no of edges:");
    scanf("%d",&e);
    for(int i=0;i<e;i++){
        printf("Enter edge u->v from u to v:");
        scanf("%d%d",&u,&w);
        addedge(u,w);
    }
    topologicalsort();
    return 0;
}