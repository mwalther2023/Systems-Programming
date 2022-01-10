#include <iostream>
#include <stdlib.h>
//#include <thread> // -std=c++11 -pthread
#include <mutex>
#include <omp.h> // -fopenmp
#include <string>
std::mutex screen;
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

int ompPrime(int n, int* a){
  omp_set_num_threads(5);
  
  int cnt = 0;
  std::cout << "Blocking: \n";
  int c[5];
  //printf("Threads Block: %d\n", omp_get_num_threads());
  for(int i = 0; i<5; i++){
    c[i] = 0;
  }
  
#pragma omp parallel
  {
  double start = omp_get_wtime();  
#pragma omp for schedule (static, n/omp_get_num_threads()) reduction(+:cnt) nowait
    for(int i = 0; i<n; i++){
      if(isPrime(a[i]) == 1){
	  cnt++;
	  c[omp_get_thread_num()]++;
      }
    }
    double stop = omp_get_wtime();
    screen.lock();
    std::cout << "\tTime for: "<<omp_get_thread_num()<<": "<<(stop-start) <<" with "<<c[omp_get_thread_num()]<<" found\n"; 
    screen.unlock();

    
  }
   
}
int ompPrimeStrip(int n, int* a){
  omp_set_num_threads(5);
  int cnt = 0;
  
  std::cout << "Striping: \n";
  int c[5];
  for(int i = 0; i<5; i++){
    c[i] = 0;
  }
#pragma omp parallel
  {
    double start = omp_get_wtime();
#pragma omp for schedule (static, omp_get_num_threads()) reduction(+:cnt) nowait
    for(int i = 0; i<n; i++){
      if(isPrime(a[i]) == 1){
	  cnt++;
	  c[omp_get_thread_num()]++;
      }
    }
    double stop = omp_get_wtime();
    screen.lock();
    std::cout << "\tTime for: "<<omp_get_thread_num()<<": "<<(stop-start) <<" with "<<c[omp_get_thread_num()]<<" found\n"; 
    screen.unlock();
  }
   
}
int main(int argc, char** argv){
  
  int min = std::stoi(argv[1]);
  int max = std::stoi(argv[2]);
  
  int n = max - min;
  int numThreads = 4;
  
  int* arr = (int*)malloc(n*sizeof(int));
  for(int i = 0; i<n; i++){
    arr[i] = i+min;
  }

  double start = omp_get_wtime();
  int o = ompPrime(n,arr);
  double stop = omp_get_wtime();
  std::cout << "Overall time: "<<(stop-start)<< " with "<<o<<" found\n";

  double start2 = omp_get_wtime();
  int o2 = ompPrimeStrip(n,arr);
  double stop2 = omp_get_wtime();
  std::cout << "Overall time: "<<(stop2-start2)<< " with "<<o<<" found\n";
  
}
