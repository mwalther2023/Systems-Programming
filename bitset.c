#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned short bitSet;

bitSet makeBitSet();
void displayBitSet(bitSet bs);
void setBit(bitSet* bs, int index);
void clearBit(bitSet* bs, int index);
int bitValue(bitSet bs, int index);


int main(){
  bitSet bs = makeBitSet();
  displayBitSet(bs);
  setBit(&bs, 5);
  displayBitSet(bs);
  clearBit(&bs,0);
  displayBitSet(bs);

  int o = bitValue(bs,5);
  printf("%d\n",o);
}
bitSet makeBitSet(){
  bitSet s = 5;
  return s;
}
void displayBitSet(bitSet bs){
  for(int i = 16; i>-1; i--){
    if(bs & (1<<i)){
      printf("%d ",'1'-48);
    }
    else{
      printf("%d ",'0'-48);
    }
  }
  printf("\n");
}
void setBit(bitSet* bs,int index){
  bitSet t = 1<<index;
  *bs = *bs | t;
  //printf("SetBit: ");
  //displayBitSet(*bs);
  //bs = &o;
}
void clearBit(bitSet* bs,int index){
  bitSet t = 1<<index;
  *bs = *bs & ~t;
  //printf("ClearBit: ");
  //displayBitSet(*bs);
  //bs = &o;
}
int bitValue(bitSet bs, int index){
  if(bs & (1<<index)){
    return '1'-48;
  }
  else{
    return '0'-48;
  }
  
}
