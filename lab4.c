#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //posix compile with gcc -pthread lab4.c -o lab4
int isPrime(int n);
int manyPrime(int arr[]);
typedef struct parm{
  int threadNum;
  int* a;
  int* cnt;
  int start;
  int stop;
}Parm;

void* myRun(void* parm){
  Parm* theParms = (Parm*)parm;
  theParms->cnt[theParms->threadNum] = 0;
  for(int i = theParms->start; i<theParms->stop; i++){
    //printf("%d\n",theParms->a[i]);
    if(isPrime(theParms->a[i]) == 1){
      theParms->cnt[theParms->threadNum]++;
    }
  }
  printf("Thread %d: Range (%d,%d) Prime #'s: %d\n",theParms->threadNum,theParms->start,theParms->stop,theParms->cnt[theParms->threadNum]);
  
}
int main(){
  int n = 100;
  int num = 15;
  int b = isPrime(num);
  
  printf("%d, is %d\n",num,b);

  int arr[n];
  for(int i = 0; i<100; i++){
    arr[i] = i+1;
  }
  int out = manyPrime(arr);
  printf("%d\n",out);
  int numThreads = 6;
  pthread_t ths[numThreads];
  //int* c = (int*)malloc(numThreads*sizeof(int));
  int c[numThreads];
  for(int i = 0;i<numThreads;i++){
    int start = (n/numThreads)*i;
    int stop = (n/numThreads)*(i+1);
    if(n%numThreads != 0 && i == (numThreads-1)){
      stop += n%numThreads;
    }
    Parm* p = (Parm*)malloc(1*sizeof(Parm));
    p->threadNum = i;
    p->a = arr;
    p->cnt = c;
    p->start = start;
    p->stop = stop;

    pthread_create(&(ths[i]),NULL,myRun,(void*)p);
  }
  for(int i = 0; i<numThreads; i++){
    pthread_join(ths[i],NULL);
  }
  
  int o = 0;
  for(int i = 0; i<numThreads; i++){
    o+=c[i];
  }
  printf("There are %d prime #'s\n",o);
}
int isPrime(int n){
  int b = 1;
  int i = 2;
  while(i<n && b == 1){
    if(n%i == 0){
      b = 0;
    }
    i++;
  }
  return b;
}
int manyPrime(int arr[]){
  int cnt = 0;
  for(int i = 0; i<100; i++){
    if(isPrime(arr[i]) == 1){
      cnt++;
    }
  }
  return cnt;
}
