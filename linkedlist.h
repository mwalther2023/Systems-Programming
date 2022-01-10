#include <stdio.h>
#include <stdlib.h>
//#include "hcompress.h"
typedef struct tnode{
  int weight;
  int c;
  struct tnode* left;
  struct tnode* right;
  struct tnode* parent;
}tnode;
typedef struct node{
  struct tnode*  value;
  struct node* next;
}LinkedList;

LinkedList* llCreate();
int llIsEmpty(LinkedList* ll);
void llDisplay(LinkedList* ll);
void llAdd(LinkedList** ll, tnode* newValue);
void llFree(LinkedList* ll);
void list_add_in_order(LinkedList** ll, tnode* tn);
