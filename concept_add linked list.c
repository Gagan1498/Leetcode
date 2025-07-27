#include <stdio.h>
#include <stdlib.h>
/* 
  1. Struct to hold nodes
  2. A head pointer which points to the first element.
  3. malloc to allocate new node
*/
struct node{
    int number;
    struct node *next;
};

struct node* head = NULL;
int no_of_elements = 0;


void print_list(){
    struct node* temp = head;
    
    printf("Linked List: ");
    while(temp != NULL){
        printf("%d ", temp->number);
        temp = temp->next;
    }
    printf("\n");
}

int insert_front (int num){
    struct node * new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL){
        printf("\nErorr: Could not allocate new memory");
        return -1;
    }
    
    new -> number = num;
    new -> next = head;
    head = new;

    no_of_elements++;
    return 0;
}

int insert_end (int num){
    
    struct node* new = (struct node*)malloc(sizeof(struct node));

    if (new == NULL) {
    printf("Memory allocation failed\n");
    return -1;  // or some error code
    }

    if (head == NULL){
        new->number = num;
        new->next = NULL;

        head = new;
        printf("\nNumber added to linked list");
        return 0;
    }
    
    struct node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    new->number = num;
    new->next = NULL;
    temp->next = new;

    no_of_elements++;
    return 0;
}

int insert_middle (int num, int pos){
    struct node * new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL){
        printf("\nErorr: Could not allocate new memory");
        return -1;
    }
    new -> number = num;
    new -> next = NULL;

    struct node* temp = head;
    int track = 1;

    if (pos < 1 || pos > no_of_elements+1){
        printf("\nInvalid location\n");
        return -1;
    }

    if (no_of_elements == pos){
        insert_end(num);
        return 0;
    }

    if (pos == 1){
        insert_front(num);
        return 0;
    }

    while(track != pos-1){
        temp = temp -> next;
        track++;
    }
    new -> next = temp -> next;
    temp -> next = new;

    no_of_elements++;
    return 0;
}

int main() {
    char choice;
    int num, pos, option;

    do {
        printf("\nDo you want to add a new node? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            printf("Where do you want to add the number?\n");
            printf("1. Front\n2. Middle (specify position)\n3. End\n");
            printf("Enter option (1/2/3): ");
            scanf("%d", &option);

            printf("Type number to add in linked list: ");
            scanf("%d", &num);

        if (option == 1) {
            if (insert_front(num) == 0) print_list();
        } else if (option == 2) {
            printf("Enter position (starting from 1): ");
            scanf("%d", &pos);
            if (insert_middle(num, pos) == 0) print_list();
        } else if (option == 3) {
            if (insert_end(num) == 0) print_list();
        } else {
            printf("Invalid option.\n");
        }
    } 
}   while (choice == 'y' || choice == 'Y');
    return 0;
}