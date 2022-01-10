#include <stdio.h>
#include <stdlib.h>

int* fill(int* cnt){
  int max = 10;
  //int b[max]; // array on runtime stack
  int* b = (int*) malloc(10 * sizeof(int)); // bytes on the heap
  
  int c = 6; 
  for(int i = 0; i<c; i++){
    b[i] = i*2;
  }
  *cnt = c;
  return b;
}
void foo(){
  int x[20];
  for(int i = 0; i<20; i++){
    x[i] = i;
  }
}
int main(){
  int count;
  int* a;
  
  a = fill(&count);
  for(int i = 0; i<count; i++){
    printf("In main: %d: %d\n",i,a[i]);
  }

  foo();
  
  for(int i = 0; i<count; i++){
    printf("In main: %d: %d\n",i,a[i]);
  }

  free(a);
  
  
}
