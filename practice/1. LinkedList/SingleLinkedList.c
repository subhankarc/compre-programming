#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

void print(struct ListNode* head){
    struct ListNode* current = head;
    for (current = head; current != NULL; current = current -> next){
        printf("%d\n", current->data);
    }
}

int length(struct ListNode* head){
    struct ListNode* current = head;
    int count = 0;
    for (current= head; current != NULL; current = current -> next){
        count++;
    }
    return count;
}

struct ListNode* insertAtBeginning(struct ListNode* head, int data){
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode*));
    newNode->data = data;
    if (head == NULL){
        head = newNode;
        head->next = NULL;
    }else{
        newNode->next = head;
        head = newNode;
    }
    return head;
}

struct ListNode* insertAtEnd(struct ListNode* head, int data){
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode*));
    newNode->data = data;
    struct ListNode* current = head;
    if (current == NULL){
        head = newNode;
        head->next = NULL;
    }else{
        while (current-> next != NULL){
            current = current-> next;
        }
        current->next = newNode;
        newNode->next = NULL;
    }
    return head;
}

struct ListNode* insertAtGivenPosition(struct ListNode* head, int data, int position){
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode*));
    newNode->data = data;

    if (position <= 1){
        newNode->next = head;
        head = newNode;
    }
    struct ListNode* previousNode = head;
    while (--position && previousNode != NULL){
        previousNode = previousNode->next;
    }

    if (previousNode == NULL){
        return NULL;
    }

    newNode->next = previousNode->next;
    previousNode->next = newNode;

    return head;

}

void deleteFirstNode(struct ListNode** head){
    struct ListNode* temp ;
    if (head == NULL){
        return ;
    }else{
        temp = *head;
        *head = (*head)->next;
        return;
    }
}

void deleteLastNode(struct ListNode** head){
    struct ListNode* temp ;
    struct ListNode* current = *head;
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

void deleteAtGivenPosition(struct ListNode** head, int position){
    struct ListNode* temp ;
    struct ListNode* current = *head;
    if (*head == NULL){
        printf("List is empty");
        return;
    }
    if (position == 1){
        *head = (*head)-> next;
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
        free(current);
    }
    return;
}

int main(){
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->data = 1;
    struct ListNode* currentNode = head;
    for (int i=2; i <10; i++){
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->data = i;
        currentNode->next = newNode;
        currentNode = newNode;
    }

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