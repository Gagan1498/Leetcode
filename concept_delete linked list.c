#include <stdio.h>
#include <stdlib.h>

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

int delete_front(){
    struct node *temp;
    temp = head;
    
    if(head == NULL){
        printf("No elements in the list\n");
        return -1;
    }
    
    head = temp->next;
    free(temp);
    no_of_elements--;
    return 0;
}

int delete_end(){

    if (head == NULL){
        printf ("List is empty\n");
        return 0;
    }    
    
    if (head -> next == NULL){
        free(head);
        no_of_elements--;
        return 0;
    }

    struct node * temp1 = NULL;
    struct node * temp2 = NULL;

    if (head -> next != NULL) temp1 = head -> next;
    temp2 = head;

    while (temp1->next != NULL){
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }

    /*    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;*/

    temp2 -> next = NULL;
    no_of_elements--;

    free(temp1);
    return 0;
} 

int delete_position(int pos){

    if (head == NULL){
        printf ("List is empty\n");
        return 0;
    }    
    
    if (pos < 1 || pos > no_of_elements){
        printf ("Invalid position\n");
        return 0;
    }

    if (pos == 1){
        return delete_front();
    }

    if (pos == no_of_elements){
        return delete_end();
    }

    int loc = 1;
    struct node * temp1 = head;
    struct node * temp2 = NULL;

    while(loc != pos){
        temp2 = temp1;
        temp1 = temp1 -> next;
        loc++;
    }

    temp2 -> next = temp1 -> next;
    free(temp1);
    no_of_elements--;

    return 0;
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


int main(){

    int choice, pos, num;
    char c;

    do{
        printf("Do you want to modify the Linked List? Enter y or n\n");
        scanf(" %c", &c);

        if(c == 'y'){
            printf ("Enter 1 if you want to add an element in the front\n");
            printf ("Enter 2 if you want to add an element in the end\n");
            printf ("Enter 3 if you want to add an element in the middle\n");
            printf ("Enter 4 if you want to delete an element in the front\n");
            printf ("Enter 5 if you want to delete an element in the end\n");
            printf ("Enter 6 if you want to delete an element in the middle\n");

            scanf("%d", &choice);

            if (choice == 1 || choice == 2 || choice == 3){
                printf ("Enter the number: \n");
                scanf("%d", &num);
            }

            if (choice == 3 || choice == 6){
                printf("Enter the position do you want to enter: \n");
                scanf ("%d", &pos);
            }

            switch (choice){
                case 1: if (insert_front (num) == 0) print_list(); break;
                case 2: if (insert_end (num) == 0) print_list(); break;
                case 3: if (insert_middle (num, pos) == 0) print_list(); break;
                case 4: if (delete_front () == 0) print_list(); break;
                case 5: if (delete_end () == 0) print_list(); break;
                case 6: if (delete_position (pos) == 0) print_list(); break;
                default: printf("Wrong choice\n"); break;
            }
        }
    }   while(c != 'n');

    return 0;
}