#include<stdio.h>
#include<stdlib.h>

#define INF 99999

int cost[10][10], vt[10], et[10][2], vis[10], j, n;
int sum = 0;
int e = 0;

void prims();

int main() {
   int i;
   printf("Enter the number of vertices: ");
   scanf("%d", &n);

   printf("Enter the cost adjacency matrix:\n");
   for(i = 0; i < n; i++) {
       for(j = 0; j < n; j++) {
           scanf("%d", &cost[i][j]);
       }
       vis[i] = 0;
   }

   prims();

   printf("Edges of the spanning tree:\n");
   for(i = 0; i < e; i++) {
       printf("%d,%d\t", et[i][0], et[i][1]);
   }
   printf("\nTotal weight = %d\n", sum);

   return 0;
}

void prims() {
   int min, u, v, k, s;
   vis[0] = 1;
   for(s = 0; s < n - 1; s++) {
       min = INF;
       for(int i = 0; i < n; i++) {
           if(vis[i]) {
               for(int j = 0; j < n; j++) {
                   if(!vis[j] && cost[i][j] < min && cost[i][j] != 0) {
                       min = cost[i][j];
                       u = i;
                       v = j;
                   }
               }
           }
       }
       vt[s] = v;
       et[s][0] = u;
       et[s][1] = v;
       e++;
       vis[v] = 1;
       sum += min;
   }
}
