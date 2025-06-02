
#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};


struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode-> data = data;
    newNode->next = NULL;
    return newNode;
}
struct node* insert(struct node * head ,int data){
    struct node* new_node = createNode(data);
    if(head==NULL){
        head=new_node;
    }
    else{
        struct node* temp=head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
      printf("Node %d inserted \n", data);
    
    return head;
}


struct node*deleteq(struct node * head){
        struct node* temp=head;
        if(head == NULL){
            printf("nothing is there to delete in queue!!!!\n");
        }
        else if (head->next==NULL){
        free(head);
        head=NULL;
            printf("Deletion successfullyy!!\n");

        }
        else{
            head=head->next;
            free(temp);
                printf("Deletion successfullyy!!\n");

        }
    return head;
}


void display(struct node* head) {
    if (head == NULL) {
        printf("Nothing to display in queue.\n");
    }
    struct node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
  
}



int main() {
    struct node* head = NULL;
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        
        printf("1. insertion to queue\n");
        printf("2. Deletion to queue\n");
        printf("3. Display \n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
             printf("Enter the data to insert : ");
                scanf("%d", &data);
                head=insert(head, data);
                break;
            case 2:
               head=deleteq(head);
                break;
        
            case 3:
                display(head);
                break;
            case 6:
              
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
