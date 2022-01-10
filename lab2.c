#include <stdio.h>
#include <stdlib.h>
//Prototype
int* readScores(int* c);
void displayScores(int arr[], int c);



typedef struct freq {
  int num;
  int freq;
}Histogram;
void displayHistogram(Histogram arr[], int c);
int calcHistogram(Histogram** arr, int* a, int cnt);

void sortHistogram(Histogram arr[], int c);
int main(){

  //printf("Test\n");
  //int num[100];
  int count = 0;
  int n;

  //printf("ReadScores Function\n");
  // int* pn = &num[count];
  int* pc = &count;
  int* num = readScores(pc);
  //printf("%d\n",*pc); //prints 12
  /*
  while(scanf("%d", &n) != EOF && count != 12){
    printf("Scanned: %d\n",n);
    num[count] = n;
    count++;
  }
  */

  
  printf("DisplayScore Function\n");
  displayScores(num,count);
  /*
  for(int i = 0; i<count; i++){
    printf("Score %d: %d\n", i, num[i]);
  }
  */


  printf("Histogram\n");
  //Histogram f[count];
  int a[count];
  for(int i = 0; i<count; i++){
    a[i] = num[i];
  }

  
  int u = a[0];
  int uC = 1;
  int temp[12];
  temp[0] = a[0];
  //f[0].num = a[0];
  int check = 0;

  Histogram* hist;
  int* histC = &uC;
  
  /*
  for(int i = 0; i<count; i++){
    //printf("%d, %d, %d\n",u, a[i], uC);
    if(u != a[i]){
      for(int x = 0; x<uC; x++){
	if(a[i] == temp[x]){
	  check++;
	}
      }
      
      if(check == 0){
	temp[uC] = a[i];
	f[uC].num = a[i];
	u = a[i];
	uC++;
	
      }
      check = 0;
    }
  }
  */
  printf("CalcHisto\n");
  uC = calcHistogram(&hist, num, count);
  /*
  for(int i = 0; i<12; i++){
    f[i].freq = 0;
    for(int x = 0; x<12; x++){
      if(f[i].num == a[x]){
	f[i].freq++;
      }
    }
  }
  */
  printf("Unique Numbers: %d\n",uC);
  /*
  for(int i = 0; i<uC; i++){
    printf("%d\n",temp[i]);
  }
  */
  printf("Display Histogram\n");
  displayHistogram(hist, uC);
  printf("Sort Hisotgram\n");
  sortHistogram(hist, uC);
  displayHistogram(hist, uC);
  /*
  for(int i = 0; i<uC; i++){
    printf("Value %d: freq %d\n",f[i].num,f[i].freq);
  }
  */
  
  int* uNum = &uC;
  //calcHistogram(freqP, uNum);

  free(hist);
  free(num);
  return 0;
}

int* readScores(int* c){
  int* arr = (int*)malloc(12*sizeof(int));
  int r;
  int i = 0;
  //int in = scanf("%d",&r);
  while(scanf("%d", &r) != EOF){
    
    //printf("%d\n", r);
    *(arr+i) = r;
    *c = *c+1;
    i++;
  }
  return arr;
}
void displayScores(int arr[], int c){
  for(int i = 0; i<c; i++){
    printf("Score %d: %d\n",i,arr[i]);
  }
}
int calcHistogram(Histogram** arr, int* a, int cnt){
  Histogram* hist = (Histogram*)malloc(cnt*sizeof(Histogram));
  
  int u = *a;
  int uC = 0;
  int temp[cnt];
  temp[0] = *a;
  int check = 0;
   for(int i = 0; i<cnt; i++){
    //printf("%d, %d, %d\n",u, a[i], uC);
     if(u != *(a+i)){
      for(int x = 0; x<uC; x++){
	if(*(a+i) == temp[x]){
	  check++;
	}
      }
      
      if(check == 0){
	temp[uC] = *(a+i);
	(hist+uC) -> num = *(a+i);
	u = *(a+i);
	uC++;
	
      }
      check = 0;
    }
  }
  
  
  
  for(int i = 0; i<cnt; i++){
    (hist+i) -> freq = 0;
    //*(arr+i).freq = 0;
    int temp = (hist+i)->num;
    
    for(int x = 0; x < cnt; x++){
      if(temp == *(a+x)){
	(hist+i)->freq++;
      }
    }
  }
  
  
  *arr = hist;

  return uC;
}
void displayHistogram(Histogram arr[], int c){
  
  //printf("%d\n",c);
  for(int i = 0; i<c; i++){
    printf("Value %d: freq %d\n",arr[i].num,arr[i].freq);
  }
      
}
void sortHistogram(Histogram* arr, int c){
  /*
  struct freq max = arr[0];
  struct freq out[c];
  for(int i = 0; i<c; i++){
    for(int x = 0; x<c; x++){
      if(max.freq < arr[x].freq){
	//struct freq temp = max;
	max = arr[x];
      }
    }
    out[i] = max;
    
  }
  */
  //displayHistogram(out, c);
  for(int i = 0; i<c-1; i++){
    for(int j = 0; j < c-i-1; j++){
      if((arr+j)->freq < (arr+j+1)->freq){
	int tempF = (arr+j)->freq;
	int tempN = (arr+j)->num;
	(arr+j)->freq = (arr+j+1)->freq;
	(arr+j)->num = (arr+j+1)->num;
       	(arr+j+1)->freq = tempF;
	(arr+j+1)->num = tempN;
      }
    }
  }
}
