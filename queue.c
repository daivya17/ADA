// Online C compiler to run C program online
#include <stdio.h>
#define SIZE 2
void insert(int );
void deleteq();
void display();
int queue[SIZE];
int front, rear =-1;

void main(){
    int data,choice;
         while(1){
        printf("\n\n*****Menuu*****\n");
        printf("1. insert\n");
        printf("2. delete\n");
        printf("3. Display\n");
        printf("Enter the your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the value to be insert: ");
            scanf("%d",&data);
            insert(data);
            break;
            case 2: 
            deleteq();
            break;
            case 3: 
            display();
            break;
            default:
            printf("wrong selection!!!!");
            break;
        }
    }
}


void insert(int data){
    if(rear==SIZE-1){
        printf("queue is fulll..!!!");
    }
    else if (front==-1){
        front=0;
        
    }
    else{
        rear++;
        queue[rear]=data;
         printf("Insertion Success!!!\n");
    
    }
    
}


void deleteq(){
     if (front == -1) {  
        printf("Underflow!!!\n");
    } else {
        printf("Deleted: %d\n", queue[front]);  
        if (front == rear) {  
            front = rear = -1;  
            
        }
        front++;
    }
}



void display() {
    if (front == -1) {
        printf("Queue is empty!!!\n");
    } else {
        printf("Elements in the queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
