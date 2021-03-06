#include <iostream>
#include <stdlib.h>
#include <thread> // -std=c++11 -pthread

int isPrime(int n){
  int b = 1;
  int i = 2;
  while(i<n && b==1){
    if(n%i == 0){
      b = 0;
    }
    i++;
  }
  return b;
}
void* myRun(int n, int* a, int* cnt, int start, int stop){
  cnt[n] = 0;
  for(int i = start; i<stop; i++){
    if(isPrime(a[i]) == 1){
      cnt[n]++;
    }
  }
  std::cout<<"Thread: "<<n<< "Range: ("<<start<<", "<<stop<<") Prime #'s: "<<cnt[n]<<"\n";
}
int main(){
  int n = 90;
  int numThreads = 4;

  int t = isPrime(11);
  std::cout<<t<<"\n";

  
  int* arr = (int*)malloc(n*sizeof(int));
  for(int i = 0; i<n; i++){
    arr[i] = i+10;
  }

  int* cnt = (int*)malloc(numThreads*sizeof(int));
  std::thread* ths[numThreads];
  for(int i = 0; i<numThreads;i++){
    int start = (n/numThreads)*i;
    int stop = (n/numThreads)*(i+1);
    if(n%numThreads != 0 && i == (numThreads-1)){
      stop += n%numThreads;
    }

    std::thread* th = new std::thread(myRun, i, arr, cnt, start, stop);
    ths[i] = th;
  }
  for(int i = 0; i<numThreads; i++){
    ths[i]->join();
  }
  int o = 0;
  for(int i = 0; i<numThreads; i++){
    o += cnt[i];
  }
  std::cout << "Prime #'s: "<<o<<"\n";
}
