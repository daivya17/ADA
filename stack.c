
#include <stdio.h>

#define size 2
void push(int);
void pop();
void display();
int stack[size],top = -1;
void main(){
    int value, choice;
    while(1){
        printf("\n\n*****Choice*****\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. Display\n");
        printf("Enter the your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the value to be insert: ");
            scanf("%d",&value);
            push(value);
            break;
            case 2: pop();
            break;
            case 3: display();
            break;
            default:
            printf("wrong selection!!!!");
            break;
        }
    }
}
void push (int value){
    if(top == size-1)
    printf("\nStack is Fulll!!! Insertion is not possible!!1");
    else{
        top++;
        stack[top] = value;
        printf("\nInsertion success!!!");

    }
}
void pop(){
    if(top == -1)
    printf("\nStack is empty!!! Deletion is not possible!!");
    else{
        printf("\nDeleted\n: %d", stack[top]);
        top--;
    }
}
void display(){
    if (top == -1)
    printf("\nStack is emptyyy!!");
    else{
        int i;
        printf("\nStack elements are:\n");
        for(i=top; i>=0; i--)
        printf("%d\n", stack[i]);
    }
}

