#include <stdio.h>
#include <stdlib.h>



typedef struct coord{
  int x;
  int y;
  int z;
  //struct coord* point;
} coordinate;

//typedef struct coord coordinate;

int main(){
  coordinate p1;
  
  p1.x = 5;
  printf("%d\n",p1.x);
}
