#include <stdio.h>
//Prototype
int doubleIt(int a);

void swap(int* x, int* y){
  //printf("spB: %d and %d\n", x,y);

  int temp = *x;
  *x = *y;
  *y = temp;

  //printf("spA: %d and %d\n", x,y);
}
void xyz(int arr[]){
  
}

struct cord{
  int x;
  int y;
  int z;
};

int main(){

  struct cord cd;

  cd.x = 5;
  cd.y = 8;
  cd.z = 10;

  printf("%d\n",cd.x);
  
  /*
  int a[10]; // C - type of a is int*

  *a = 9;
  //a[2] = 5;
  *(a+2) = 6;
  a[3] = 8;

  printf("%d\n",a[2]);
  xyz(a);
  */
  /*
  int a;
  int b;

  a = 5;
  b = 8;

  swap(&a,&b);
  printf("%d and %d\n",a,b);
  */
  /*
  //&a // address of the variable a
  int* x; // int* means int pointer type
  x = &a;

  int c = *x; // pointer dereference
    
  printf("%d and %d\n",a,c);
  */

  /*
  //printf("Hello World\n");
  int x; // char-1, short-2, int-4, long-8
  int y = 8;
  x = 5;

  double z = 5.3; //float-4, double-8
  */
  /*
  //printf("this is the first value: "+ x+ "and the second: "+y);
  printf("This is the first value %d and the second %lf\n",x,z);

  char c = 'w';
  //char c = 119;
  printf("My char is %c\n",c);


  if(x == 2){
    printf("equal\n");
  }
  else{
    printf("not equal\n");
  }
  
  while(x<5){

  }
  for(int i = 0; i<5; i++){

  }
  */
  /*
  int result = doubleIt(x);
  printf("Result is %d\n",result);
  
  */
  return 0;
}

int doubleIt(int a){
  return a*2;
}
