#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <thread> // -std=c++11 -pthread

void myRun(int n, int* a, int* b, int* c, int start, int stop){
  std::cout << "Thread: " << n << " From range ("<<start<<", "<<stop<<")\n";
  for(int i = start; i<stop; i++){
    c[i] = a[i] + b[i];
  }
}
int main(){
  int n = 100;
  int* a = (int*)malloc(n*sizeof(int));
  int* b = (int*)malloc(n*sizeof(int));
  int* c = (int*)malloc(n*sizeof(int));
  
  for(int i = 0; i<n; i++){
    a[i] = i;
    b[i] = i;
  }

  //Vec Add
  //for(int i = 0; i<n; i++){
  //c[i] = a[i] + b[i];
  //}

  
  int numThreads = 4;
  std::thread* ths[numThreads];
  for(int i = 0; i<numThreads; i++){
    int start = (n/numThreads)*i;
    int stop = (n/numThreads)*(i+1);
    
    std::thread* th = new std::thread(myRun, i, a, b, c, start, stop);
    ths[i] = th;
  }

  for(int i = 0; i<numThreads; i++){
    ths[i]->join();
  }
  for(int i = 0; i<n; i++){
    std::cout << "value " <<c[i]<<"\n";
	   
  }
}
