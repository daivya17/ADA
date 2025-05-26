#include<stdio.h>
#define max 10
int board[max];
int n;
int issafe(int row,int col){
    for(int i=0;i<row;i++){
        if(board[i] == col || board[i]-i == col-row || board[i]+i == col+row){
            return 0;
        }
    }
    return 1;
}
void printboard() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}
void solve(int row){
    if(row==n){
        printboard();
        return;
    }
    for(int col=0;col<n;col++){
        if(issafe(row,col)){
            board[row] = col;
            solve(row+1);
        }
    }
}
int main(){
    printf("Enter board size:");
    scanf("%d", &n);
    solve(0);
    return 0;
}
