#include<stdio.h>
#include<stdlib.h>

struct CLLNode {
    int data;
    struct CLLNode* next;
};

void print(struct CLLNode* head){
    struct CLLNode* current = head;
    do{
        printf("%d\n", current->data);
        current = current -> next;
    } while( current != head);
}

int length(struct CLLNode* head){
    struct CLLNode* current = head;
    if (head == NULL) return 0;
    int count = 0;
    do{
        count++;
        current = current -> next;
    } while( current != head);
    return count;
}

struct CLLNode* insertAtBeginning(struct CLLNode* head, int data){
    struct CLLNode* newNode = (struct CLLNode*)malloc(sizeof(struct CLLNode*));
    struct CLLNode* current = head;
    newNode->data = data;
    if (current == NULL){
        head = newNode;
        head->next = head;
        return head;
    }

    while(current->next != head){
        current = current->next;
    }
    newNode->next = head;
    current->next = newNode;
    head = newNode;
    return head;
}

struct CLLNode* insertAtEnd(struct CLLNode* head, int data){
    struct CLLNode* newNode = (struct CLLNode*)malloc(sizeof(struct CLLNode*));
    newNode->data = data;
    struct CLLNode* current = head;
    if (current == NULL){
        head = newNode;
        head->next = head;
    }else{
        while (current-> next != head){
            current = current-> next;
        }
        current->next = newNode;
        newNode->next = head;
    }
    return head;
}

struct CLLNode* insertAtGivenPosition(struct CLLNode* head, int data, int position){
    struct CLLNode* newNode = (struct CLLNode*)malloc(sizeof(struct CLLNode*));
    newNode->data = data;

    if (position <= 1){
        newNode->next = head;
        head = newNode;
    }
    struct CLLNode* previousNode = head;
    while (--position && previousNode->next != head){
        previousNode = previousNode->next;
    }

    if (previousNode->next == head){
        return NULL;
    }

    newNode->next = previousNode->next;
    previousNode->next = newNode;

    return head;

}

void deleteFirstNode(struct CLLNode** head){
    struct CLLNode* temp = *head ;
    struct CLLNode* current = *head;
    if (current == NULL){
        return ;
    }else{
        while (current-> next != *head){
            current = current-> next;
        }
        current->next = (*head)->next;
        *head = (*head)->next;
        free(temp);
        return;
    }
}

void deleteLastNode(struct CLLNode** head){
    struct CLLNode* temp = *head;
    struct CLLNode* current = *head;
    if (*head == NULL){
        return;
    }
    while (current->next != *head){
        temp = current;
        current = current->next;
    }

    temp->next = current->next;
    free(current);
    return;
}

void deleteAtGivenPosition(struct CLLNode** head, int position){
    struct CLLNode* temp = *head;
    struct CLLNode* current = *head;
    if (*head == NULL){
        printf("List is empty");
        return;
    }
    if (position == 1){
        *head = (*head)-> next;
        while(current->next != *head){
            current = current->next;
        }
        current->next = (*head)->next;
        *head = (*head)->next;
        free(head);
        return;
    }

    while(--position && current-> next != *head){
        temp = current;
        current = current->next;
    }

    if (current-> next  == *head){
        printf("Position does not exist");
        return;
    }else{
        temp->next = current->next;
        free(current);
    }
    return;
}

int main(){
    struct CLLNode* head = (struct CLLNode*)malloc(sizeof(struct CLLNode));
    head->data = 1;
    struct CLLNode* currentNode = head;
    for (int i=2; i <10; i++){
        struct CLLNode* newNode = (struct CLLNode*)malloc(sizeof(struct CLLNode));
        newNode->data = i;
        currentNode->next = newNode;
        currentNode = newNode;
    }
    currentNode ->next = head;

    print(head);
    printf("linked list size is %d\n", length(head));

    head = insertAtBeginning(head, 0);
    print(head);
    printf("linked list size is %d\n", length(head));

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