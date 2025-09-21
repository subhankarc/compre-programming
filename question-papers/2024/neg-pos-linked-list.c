#include<stdio.h>
#include<stdlib.h>

struct SLLNode {
    int data;
    struct SLLNode* next;
};

struct HEAD {
    struct SLLNode* POSP;
    struct SLLNode* NEGP;
};

int check_sum(struct HEAD* head){
    struct SLLNode* positive = head->POSP;
    struct SLLNode* negative = head->NEGP;
    int positiveSum =0, negativeSum = 0;
    while (positive != NULL){
        positiveSum += positive->data;
        positive = positive->next;
    }
    while (negative != NULL){
        negativeSum += abs(negative->data);
        negative = negative->next;
    }

    if (positiveSum == negativeSum){
        return 1;
    }else {
        return 0;
    }
}

int main(){
    printf("Enter data");
    struct HEAD* head = (struct HEAD*)malloc(sizeof(struct HEAD*));
    head->NEGP = NULL;
    head->POSP = NULL;
    int enteredNumber;
    struct SLLNode* lastPositive = NULL;
    struct SLLNode* lastNegative = NULL;
    while(1){
        scanf("\n %d", &enteredNumber);
        printf("\nEntered number is %d", enteredNumber);
        if (enteredNumber == 0){
            break;
        }else if(enteredNumber >0){
            printf("\nEntered number is positive");
            struct SLLNode* tempPositive = (struct SLLNode*)malloc(sizeof(struct SLLNode*));
            tempPositive->data = enteredNumber;
            tempPositive->next = NULL;
            if(lastPositive == NULL){
                head->POSP = tempPositive;
                lastPositive = tempPositive;
            }else{
                lastPositive->next = tempPositive;
                lastPositive = tempPositive;
            }
        }else{
            struct SLLNode* tempNegative = (struct SLLNode*)malloc(sizeof(struct SLLNode*));
            tempNegative->data = enteredNumber;
            tempNegative->next = NULL;
            if(lastNegative == NULL){
                head->NEGP = tempNegative;
                lastNegative = tempNegative;
            }else{
                lastNegative->next = tempNegative;
                lastNegative = tempNegative;
            }
        }
    }

    printf("Negative List is ");
    struct SLLNode* firstNegative = head->NEGP;
    while(firstNegative != NULL){
        printf("%d \t", firstNegative->data);
        firstNegative = firstNegative->next;
    }

    printf("Positive List is ");
    struct SLLNode* firstPositive = head->POSP;
    while(firstPositive != NULL){
        printf("%d \t", firstPositive->data);
        firstPositive = firstPositive->next;
    }

    int returned = check_sum(head);

    if (returned == 1){
        printf("\n value match!");
    }else{
        printf("\n value does not match");
    }
}