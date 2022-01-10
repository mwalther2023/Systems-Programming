#include <iostream>
#include <omp.h> // -fopenmp
#include <stdlib.h>
#include <mutex>
#include <stdio.h>
std::mutex screenLock;

int main(){
  /*
  //omp_set_dynamic(0);
  omp_set_num_threads(4);
  //std::cout << omp_get_num_threads()<<"\n";
#pragma omp parallel
  {
    int tn = omp_get_thread_num();
    int numT = omp_get_num_threads();
    screenLock.lock();
    std::cout << "Im thread: "<< tn << " of "<< numT<<"\n";
    screenLock.unlock();

#pragma omp for
  for(int i = 0; i<10; i++){
    screenLock.lock();
    std::cout << tn << ": "<< i<<"\n";
    screenLock.unlock();
  }
  }
  std::cout << "Word\n";
  */
  omp_set_num_threads(4);
  int n = 1000;

  double epi = 0.0;
#pragma omp parallel
  #pragma omp for schedule(static, 2500) reduction(+:epi)
  for(int i = 0; i<n; i++){
    double term = 1.0/((2*i)+1);
    int sign = 1;
    if(i%2 == 1){
      sign = -1;
    }
    
    epi = epi +(sign*term);
    
  }
  
  epi = epi * 4.0;
  std::cout << epi << "\n";
  
}
