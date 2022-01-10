#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
//#include "hcompress.h"

LinkedList* llCreate(){
  return NULL;
}
int llIsEmpty(LinkedList* ll){
  return (ll == NULL);
}
void llDisplay(LinkedList* ll){
  printf("in llDisplay\n");
  LinkedList* p = ll;
  printf("[");

  while(p != NULL){
    printf("%d, ",(*p).value->c);
    p = p->next;
  }
  printf("]\n");
}
void llAdd(LinkedList** ll, tnode* newValue){
  printf("In llAdd\n");
  //Create the new node
  LinkedList* newNode = (LinkedList*)malloc(1*sizeof(LinkedList));
  newNode->value = newValue;
  newNode->next = NULL;
  
  //Find the end of the list
  LinkedList* p = *ll;
  //printf("p created\n");
  if(p == NULL){
    //printf("If p==NULL\n");
    *ll = newNode;
  }
  else{
    //printf("else\n");
    while(p->next != NULL){
      p = p->next;
    }
    //Attach it the end
    p->next = newNode;
  }
  printf("end of llAdd: %d\n",newValue->c);
}
void llFree(LinkedList* ll){
  LinkedList* p = ll;

  while(p != NULL){
    LinkedList* oldP = p;
    p = p->next;
    free(oldP);
  }
}
void list_add_in_order(LinkedList** ll, tnode* tn){
  //printf("in list_add_in_order\n");
  
  LinkedList* l = *ll;
  LinkedList* p = (LinkedList*)malloc(1*sizeof(LinkedList));
  p->value = tn;
  p->next = NULL;
  //printf("%d, %d\n", tn->c, tn->weight);
  if(*ll == NULL){
    *ll = p;
    //printf("ll is NULL\n");
  }
  else if((*ll)->value->weight >= p->value->weight){
    p->next = *ll;
    *ll = p;
  }
  else{
    LinkedList* t = l->next; 
    //printf("Letter: %d Freq: %d\n",tn->c, tn->weight);//While seg faults @ Letter: 10, Freq: 1
    while(t != NULL && p->value->weight > t->value->weight){	
      l = l->next;
      t = t->next;
    }
    
    l->next = p;
    p->next = t;
    
  }
  printf("Letter: %d Freq: %d\n",tn->c, tn->weight);//While seg faults @ Letter: 10, Freq: 1
  
}
