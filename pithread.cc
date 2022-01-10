#include <iostream>
#include <thread> // -std=c++11 -pthread
#include <mutex>

double epi;
std::mutex epiLock;
void pithread(int start, int stop){
  //double localEpi = 0.0
  for(int i = start; i<stop; i++){
    double term = 1.0/((2*i)+1);
    int sign = 1;
    if(i%2 == 1){
      sign = -1;
    }
    epiLock.lock();
    epi = epi +(sign*term);
    epiLock.unlock();
  }
  //epi += localEpi;
}

int main(){
  int n = 1000;

  epi = 0.0;
  int nth = 4;
  std::thread* ths[nth];
  for(int i = 0; i<nth; i++){
    int start = (n/nth)*i;
    int stop = (n/nth)*(i+1);
    ths[i] = new std::thread(pithread, start, stop);
  }

  for(int i = 0; i<nth; i++){
    ths[i]->join();
  }
  epi = epi * 4.0;

  std::cout << epi << "\n";
}
