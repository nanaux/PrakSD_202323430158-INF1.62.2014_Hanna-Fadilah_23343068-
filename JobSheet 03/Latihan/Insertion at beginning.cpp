//Created by 23343068_Hanna Fadilah

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct node *node) { // Perbaiki tipe data menjadi struct node
    while (node != NULL) {
        printf("%d ", node->data); // Tambahkan spasi untuk memisahkan setiap data
        node = node->next;
    }
}

int main() {
    struct node* head = NULL;
    push(&head, 7);
    push(&head, 1);
    printf("Created Linked List is: ");
    printList(head);
    
    return 0;
}
