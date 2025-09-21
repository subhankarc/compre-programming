#include<stdio.h>
#include<stdlib.h>

struct DLLNode {
    int data;
    struct DLLNode* next;
    struct DLLNode* previous;
};

void print(struct DLLNode* head){
    struct DLLNode* current = head;
    struct DLLNode* previous;
    while (current != NULL){
        printf("%d\n", current->data);
        previous = current;
        current = current -> next;
    }
    printf("Now printing in reverse\n");
    while (previous){
        printf("%d\n", previous->data);
        previous = previous->previous;
    }
}

int length(struct DLLNode* head){
    struct DLLNode* current = head;
    int count = 0;
    for (current= head; current != NULL; current = current -> next){
        count++;
    }
    return count;
}

struct DLLNode* insertAtBeginning(struct DLLNode* head, int data){
    struct DLLNode* newNode = (struct DLLNode*)malloc(sizeof(struct DLLNode));
    newNode->data = data;
    if (head == NULL){
        head = newNode;
        head->previous = NULL;
        head->next = NULL;
    }else{
        newNode->next = head;
        newNode->previous = NULL;
        head->previous = newNode;
        head = newNode;
    }
    return head;
}

struct DLLNode* insertAtEnd(struct DLLNode* head, int data){
    struct DLLNode* newNode = (struct DLLNode*)malloc(sizeof(struct DLLNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->previous = NULL;
    struct DLLNode* current = head;
    if (current == NULL){
        head = newNode;
    }else{
        while (current-> next != NULL){
            current = current-> next;
        }
        newNode->previous = current;
        current->next = newNode;
    }
    return head;
}

struct DLLNode* insertAtGivenPosition(struct DLLNode* head, int data, int position){
    struct DLLNode* newNode = (struct DLLNode*)malloc(sizeof(struct DLLNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->previous = NULL;
    if (position <= 1){
        newNode->next = head;
        head = newNode;
    }
    struct DLLNode* previousNode = head;
    while (--position && previousNode != NULL){
        previousNode = previousNode->next;
    }

    if (previousNode == NULL){
        return NULL;
    }

    newNode->previous = previousNode;
    newNode->next = previousNode->next;
    if(previousNode->next)
        previousNode->next->previous = newNode;
    previousNode->next = newNode;

    return head;

}

void deleteFirstNode(struct DLLNode** head){
    struct DLLNode* temp ;
    if (head == NULL){
        return ;
    }else{
        temp = *head;
        *head = (*head)->next;
        (*head) ->previous = NULL;
        return;
    }
}

void deleteLastNode(struct DLLNode** head){
    struct DLLNode* temp ;
    struct DLLNode* current = *head;
    if (*head == NULL){
        return;
    }
    while (current->next != NULL){
        temp = current;
        current = current->next;
    }

    temp->next = NULL;
    free(current);
    return;
}

void deleteAtGivenPosition(struct DLLNode** head, int position){
    struct DLLNode* temp ;
    struct DLLNode* current = *head;
    if (*head == NULL){
        printf("List is empty");
        return;
    }
    if (position == 1){
        *head = (*head)-> next;
        (*head) ->previous = NULL;
        free(current);
        return;
    }

    while(--position && current!= NULL){
        temp = current;
        current = current->next;
    }

    if (current == NULL){
        printf("Position does not exist");
        return;
    }else{
        temp->next = current->next;
        if (current->next)
            current->next->previous = temp;
        free(current);
    }
    return;
}

int main(){
    struct DLLNode* head = (struct DLLNode*)malloc(sizeof(struct DLLNode));
    head->data = 1;
    struct DLLNode* currentNode = head;
    currentNode->previous = NULL;
    for (int i=2; i <10; i++){
        struct DLLNode* newNode = (struct DLLNode*)malloc(sizeof(struct DLLNode));
        newNode->data = i;
        currentNode->next = newNode;
        newNode->previous = currentNode;
        currentNode = newNode;
    }
    currentNode->next = NULL; // Ensure the last node's next is NULL

    print(head);
    printf("linked list size is %d\n", length(head));

    printf("AFTER ADDING NODE IN THE BEGINNING\n");
    head = insertAtBeginning(head, 0);
    print(head);
    printf("linked list size is %d\n", length(head));

    printf("AFTER ADDING NODE IN THE END\n");
    head = insertAtEnd(head, 10);
    print(head);
    printf("linked list size is %d\n", length(head));

    head = insertAtGivenPosition(head, 500, 5);
    print(head);
    printf("linked list size is %d\n", length(head));

    deleteFirstNode(&head);
    print(head);
    printf("linked list size is %d\n", length(head));

    deleteLastNode(&head);
    print(head);
    printf("linked list size is %d\n", length(head));

    deleteAtGivenPosition(&head, 5);
    print(head);
    printf("linked list size is %d\n", length(head));

    return 0;
}