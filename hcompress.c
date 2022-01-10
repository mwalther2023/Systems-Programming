#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
//#include "hcompress.h"
tnode* createFreqTable(char* fileName){
  tnode* t = (tnode*)malloc(128*sizeof(tnode));
  printf("Array: \n");
  for(int i = 0; i<128; i++){
    //printf("%d\n",(t+i)->c);
    (t+i)->c = i;
  }
  FILE *file;
  file = fopen(fileName,"r");
  int ch;
  //int i = 0;
  if(file){
    while((ch = getc(file)) != EOF){
      //putchar(t[c].c);
      //(t+ch)->c = ch;
      (t+ch)->weight++;
      printf("%d, %d\n",ch, (t+ch)->weight);
      //i++;
    }
    fclose(file);
  }
  
 
  return t;
}
tnode* createHuffmanTree(tnode* leafNodes){
  LinkedList* ll = llCreate();
  printf("In createHuffmanTree\n");
  //(ll)->value = leafNodes+1;
  //ll->next->value = leafNodes+2;
  //ll->next = NULL;
  //llAdd(&ll,leafNodes);

  for(int i = 0; i<128; i++){
    //printf("%d\n",i);
    if((leafNodes+i)->weight != 0){
      list_add_in_order(&ll,(leafNodes+i));
    }
  }
  
  llDisplay(ll);

  tnode* newNode = (tnode*)malloc(1*sizeof(tnode));
  tnode* l = (tnode*)malloc(1*sizeof(tnode));
  tnode* r = (tnode*)malloc(1*sizeof(tnode));
  LinkedList* temp = ll;
  LinkedList* newList = llCreate();
  //printf("At loop\n");

  //for(int i = 0; i<128; i++){
  int b = 0;
  
  while(temp->next != NULL && b != 1){
    /*
    for(int x = i; x<i+1; x++){
      printf("sliding temp down: %d, %d\n",i,x);
      temp = temp->next;
    }
    */
    l = temp->value;
    r = temp->next->value;
    printf("At if: (%d,%d) Weight: (%d,%d)\n", l->c,r->c, l->weight, r->weight);
    
    
    if(r->weight == l->weight){
	//printf("Linking...\n");
      newNode->weight = r->weight + l->weight;
      newNode->c = newNode->weight;
      newNode->right = r;
      newNode->left = l;
	
      r->parent = newNode;
      l->parent = newNode;
      printf("Parent weight: %d  For: (%d,%d): NewNode: %d\n",newNode->weight,l->c,r->c, newNode->c);
      temp = temp->next;
      //printf("Linked\n");
      list_add_in_order(&newList,newNode);
    }
    else if(l->c == r->c){
     list_add_in_order(&newList,l); 

     temp = NULL;
     b = 1;
     printf("Breaking\n");
    }
   
    else{
      list_add_in_order(&newList,l);
    }
    temp = temp->next;
    //newNode = NULL;
  }
      list_add_in_order(&newList,temp->value);
  
  llDisplay(newList);
  
  printf("End of createHuffmanTree\n");
}

void encodeFile(char* file, tnode* leaf){

}
void decodeFile(char* file, tnode* root){
  
}
int main(int argc, char *argv[]){
  //Check to make sure the input parameters are correct
  /*
  if(argc != 3){
    printf("Error: The correct format is \"hcompress -e filename\" or \"hcompress -d filename.huf\"\n");
    fflush(stdout);
    exit(1);
  }
  */
  //Create the frequency table by reading the generic file
  //struct tnode* leafNodes = createFreqTable("decind.txt");
  struct tnode* leafNodes = createFreqTable("hTest.txt");
 

  
  //Create the huffman tree from the frequency table
  struct tnode* treeRoot = createHuffmanTree(leafNodes);
  /*
  //encode
  if(strcmp(argv[1],"-e")==0){
    //Pass the leafNodes since it will process bottom up
    encodeFile(argv[2],leafNodes);
  }
  //decode
  else{
    //Pass the tree root since it will process top down
    decodeFile(argv[2],treeRoot);
  }
  */
  return 0;
  
}

