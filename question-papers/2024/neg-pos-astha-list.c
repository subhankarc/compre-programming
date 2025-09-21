#include <stdio.h>
#include <stdlib.h>

struct slnode {
  int data;
  struct slnode *next;
};

struct HEAD {
  struct slnode *NEGP;
  struct slnode *POSP;
};

int checksum(struct HEAD *head) {
  struct slnode *negp = head->NEGP;
  struct slnode *posp = head->POSP;

  int negcount = 0;
  int poscount = 0;
  printf("NEG data : ");
  while (negp != NULL) {
    negcount = negcount + abs(negp->data);
    printf("%d  ", negp->data);
    negp = negp->next;
  }
  printf("\n");
  printf("POS data : ");
  while (posp != NULL) {
    poscount = poscount + (posp->data);
    printf("%d  ", posp->data);
    posp = posp->next;
  }
  printf("\n");
  if (poscount == negcount) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  struct HEAD *H = (struct HEAD *)malloc(sizeof(struct HEAD));

  H->NEGP = NULL;
  H->POSP = NULL;
  int in;

  int flag = 1;
  printf("Enter data: ");
  while (flag == 1) {
    scanf("%d", &in);
    if (in == 0) {
      flag = 0;
      printf("%d", in);
    } else {

      printf("%d, ", in);
      if (in < 0) {
        printf("negative loop \n");
        // printf("positive loop \n");

        if (H->NEGP == NULL) {
        struct slnode *newnode =
              (struct slnode *)malloc(sizeof(struct slnode));
          newnode->data = in;
          newnode->next = NULL;
          H->NEGP = newnode;
        } else {
          struct slnode *temppp = H->NEGP;
          struct slnode *newnode =
              (struct slnode *)malloc(sizeof(struct slnode));
          newnode->data = in;
          newnode->next = NULL;
          while (temppp->next != NULL) {
            temppp = temppp->next;
          }
          temppp->next = newnode;
        }
      } else {
        printf("positive loop \n");
        if (H->POSP == NULL) {
        struct slnode *newnode =
              (struct slnode *)malloc(sizeof(struct slnode));
          newnode->data = in;
          newnode->next = NULL;
          H->POSP = newnode;
        } else {
          struct slnode *newnode =
              (struct slnode *)malloc(sizeof(struct slnode));
          newnode->data = in;
          newnode->next = NULL;
          struct slnode *temppp = H->POSP;
          while (temppp->next != NULL) {
            temppp = temppp->next;
          }
          temppp->next = newnode;
        }
      }
    }
  }
  printf("\n");

  printf("NEGATIVE LIST: ");
  struct slnode* firstnp = H->NEGP;
  while (firstnp != NULL) {
    printf("%d ", firstnp->data);
    firstnp = firstnp ->next;
  }
  printf("\n");
  printf("POSITIVE LIST: ");
  struct slnode* firstpp = H->POSP;
  while (firstpp != NULL) {
    printf("%d ", firstpp->data);
    firstpp = firstpp -> next;
  }
  printf("\n");

  int ans = checksum(H);
  if (ans == 1) {
    printf("Sums of two lists are equal");
  } else {
    printf("Sums of two lists are unequal");
  }

  return 0;
}