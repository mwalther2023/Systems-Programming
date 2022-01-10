#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "duSocket.h"
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

 int main(){
 
   int sockfd = callServer("localhost",7000);

   /*
   printf("Please enter an int: \n");
   int buffer;
   //fgets(buffer,sizeof(buffer),stdin);
   scanf("%d", &buffer);
   writeInt(buffer, sockfd);
   */

   int start = readInt(sockfd);
   int stop = readInt(sockfd);
   int cnt = 0;
   for(int i = start; i<stop; i++){
     if(isPrime(i) == 1){
       cnt++;
     }
   }
   printf("Range: (%d,%d) | Node Primes: %d\n",start,stop,cnt);
   writeInt(cnt,sockfd);
   close(sockfd);

   return 0;
   
 }
