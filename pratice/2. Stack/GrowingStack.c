#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int capacity;
    int *array;
};

struct Stack* createStack(int capacity)
{
    struct Stack *s = malloc(sizeof(struct Stack));
    s->capacity = capacity;
    s->top = -1;
    s->array = malloc(s->capacity * sizeof(int));
    return s;
}

int isEmpty(struct Stack *s)
{
    return (s->top == -1);
}

int size(struct Stack *s)
{
    return (s->top + 1);
}

int isFull(struct Stack *s)
{
    return (s->top + 1 == s->capacity);
}

void doubleStack(struct Stack *s){
    s->capacity *= 2;
    s->array = realloc(s->array, s->capacity * sizeof(int));
}

void push(struct Stack *s, int data)
{
    if (isFull(s))
        doubleStack(s);
    s->array[++s->top] = data;
}

int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Nothing in stack");
        return 0;
    }
    else
        return (s->array[s->top--]);
}

int peek(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Nothing in stack");
        return 0;
    }
    else
        return (s->array[s->top]);
}

void deleteStack(struct Stack *s){
    if (s){
        if(s->array){
            free(s->array);
        }
        free(s);
    }
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