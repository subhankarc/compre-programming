#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

struct Stack
{
    struct ListNode* top;
    int size;
};

struct Stack* createStack(int capacity)
{
    struct Stack *s = malloc(sizeof(struct Stack));
    s->size = 0;
    s->top = NULL;
    return s;
}

int isEmpty(struct Stack *s)
{
    return (s->top == NULL);
}

int size(struct Stack *s)
{
    return (s->size);
}

void push(struct Stack *s, int data)
{
    struct ListNode* tempNode = malloc(sizeof(struct ListNode));
    tempNode->data = data;
    tempNode->next = s->top;
    s->top = tempNode;
    s->size += 1;
}

int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Nothing in stack");
        return 0;
    }
    struct ListNode* temp = s->top;
    s->top = temp ->next;
    int data = temp->data;
    free(temp);
    s->size -= 1;
    return data;
}

int peek(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Nothing in stack");
        return 0;
    }
    else
        return s->top->data;
}

void deleteStack(struct Stack *s){
    struct ListNode* temp, *p;
    p = s->top;
    if (p){
        temp = p->next;
        p = p->next;
        free(temp);
    }
    free(s);
}

int main(){

    int i = 0, capacity = 15;
    struct Stack *s = createStack(15);

    for (i=0; i<= capacity; i++){
        push (s, i);
    }

    printf("Top is %d\n", peek(s));
    printf("Size is %d\n", size(s));
    
    for  (i=0; i<= capacity; i++){
        printf("Popped element is %d\n", pop(s));
    }

    printf("Size is %d\n", size(s));

    if(isEmpty(s))
        printf("Stack is empty");
    else
        printf("Stack is not empty");
    deleteStack(s);
    return 0;
}