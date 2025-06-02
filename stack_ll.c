#include <stdio.h>
#include <stdlib.h>

struct node 
{
   int data;
   struct node * next;
};

struct node* create_node (int data){
    struct node*new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next=NULL;

    return new_node;
    
}

struct node* push(struct node* top,int data){
     struct node*new_node = create_node(data);
     if(top == NULL){
     top = new_node;
     }
     else{
        new_node -> next = top;
        top = new_node;
     }

     return top;

             
}


struct node * pop(struct node* top){
    struct node *temp=top;
    if(top == NULL){
        printf("Emptyy stackkk");
    }
    else{
        top=top->next;
        free(temp);
    }
    return top;

}

void display(struct node* top){
    struct node *temp=top;
    if(top == NULL){
        printf("Emptyy stackkk");
    }
    else{
        while(temp != NULL){
            printf("%d->",temp->data);
            temp= temp->next;
        }
        printf("NULL\n");

}
}

void main(){
      struct node * top = NULL;
       int value, choice;
    while(1){
        printf("\n\n*****Choice*****\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. Display\n");
        printf("4. exit\n");

        printf("Enter the your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the value to be insert: ");
            scanf("%d",&value);
           top= push(top,value);
            break;
            case 2: 
            top=pop(top);
            break;
            case 3: display(top);
            break;
            case 4:
            exit(1);
            default:
            printf("wrong selection!!!!");
            break;
        }
    }
    
       


}
