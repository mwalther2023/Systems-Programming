#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Prototype
char** readWords(int* c);
void displayWords(char** arr, int c);



typedef struct freq {
  char* wrd;
  int freq;
}Histogram;
void displayHistogram(Histogram arr[], int c);
int calcHistogram(Histogram** arr, char** a, int cnt);

void sortHistogram(Histogram arr[], int c);
int main(){

  //printf("Test\n");
  //int num[100];
  int count = 0;
  int n;

  //printf("ReadScores Function\n");
  // int* pn = &num[count];
  int* pc = &count;
  char** wrd = readWords(pc);
  //printf("%d\n",*pc); //prints 12
  
  printf("DisplayScore Function\n");
  displayWords(wrd,count);

  printf("Histogram\n");
  //Histogram f[count];
  int uC = 0;
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
  uC = calcHistogram(&hist, wrd, count);
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
  for(int i = 0; i<count; i++){
    free(*(wrd+i));
  }
  free(wrd);
  return 0;
}

char** readWords(int* c){
  char** arr = (char**)malloc(100*sizeof(char*));
  char* r = (char*)malloc(10*sizeof(char));
  int i = 0;
  //int in = scanf("%d",&r);
  while(scanf("%s", r) != EOF){
    *(arr+i) = (char*)malloc(strlen(r)+1*sizeof(char));
    //printf("%d\n", r);
    strcpy(*(arr+i),r);
    *c = *c+1;
    i++;
  }
  free(r);
  return arr;
}
void displayWords(char** arr, int c){
  for(int i = 0; i<c; i++){
    printf("Word %d: %s\n",i,*(arr+i));
  }
}
int calcHistogram(Histogram** arr, char** a, int cnt){
  Histogram* hist = (Histogram*)malloc(cnt*sizeof(Histogram));
  printf("Top of calcHisto: %d\n",cnt);
  int uC = 0;
  //char temp[cnt];

  char* target = *a;
  int boo = 0;
  
  //strcpy(hist->wrd,target);
  hist->wrd = target;
  hist->freq = 0;
  uC++;
  for(int i = 0; i<cnt; i++){
    
    //printf("Outer loop %d, %d\n",i,uC);
    
    for(int x = 0; x<uC; x++){
      //printf("Inner loop %d\n",x);
      //printf("%s : %s\n",target, (hist+x)->wrd);
      if(boo == 0){
      if((hist+x)->wrd == NULL){
	//printf("Empty Spot placing: %s @ %d\n", target, x);
	//strcpy((hist+x)->wrd,target);
	(hist+x)->wrd = target;
	(hist+x)->freq = 1;
	uC++;
	boo = 1;
	//printf("Placed\n");
      }
      
      else if(strcmp(target,(hist+x)->wrd) == 0){
	//printf("Found: %s @ (%d,%d): Incresing freq\n",target,i,x);
	(hist+x)->freq++;
	boo = 1;
	//uC++;
	//target = *(a+i+1);
	//printf("Freq increased by 1\n");
	
      }
      
      }
      //x = 100000000; 
    }
    if(boo == 0){
      //printf("Did not find: %s : Adding to Hist\n",target);
	uC++;
	(hist+uC)->wrd=target;
	
	(hist+uC)->freq = 1;
	
	boo = 1;
	//printf("Added: %d\n",uC);	
      }
    target=*(a+i+1);
    boo = 0;
    /*
    int t = 0;
    int boo = 0;
    while(t<cnt || boo == 0){
      if((hist+t)->wrd == NULL){
	strcpy((hist+t)->wrd,target);
	(hist+t)->freq = 1;
	uC++;
	boo = 1;
      }
      else if(strcmp(target,(hist+t)->wrd) == 0){
	(hist+t)->freq++;
	boo = 1;
      }
      t++;
    }
    */
  }
  //printf("uC: %d\n",uC);
  /*
  char* u = *a;
  int uC = 0;
  //char* temp = *a; //= (char*)malloc(10*sizeof(char));
  char temp[30];
  
  //*(temp+0) = *a;
  
  int check = 0;

  for(int i = 0; i<cnt; i++){
    //printf("%d, %d, %d\n",u, a[i], uC);
    
     if(strcmp(u,*(a+i)) != 0){
       printf("%s, %s, %d\n",u, *(a+i), uC);
       for(int x = 0; x<uC; x++){

  printf("Histogram\n");
	if(strcmp(*(a+i),(temp)) == 0){
	  check++;
	}
      }
       
      if(check == 0){
	strcpy(temp, *(a+i));
	(hist+uC) -> wrd = *(a+i);
	u = *(a+i);
	uC++;
	//printf("%d\n",uC);
	
      }
      check = 0;
    }
  }
 
  
   printf("Post uC: %d\n",uC);
  for(int i = 0; i<cnt; i++){
    (hist+i) -> freq = 0;
    //*(arr+i).freq = 0;
    char* temp;
    strcpy(temp,(hist+i)->wrd);
    //printf("1st for %d\n",i);
    for(int x = 0; x < cnt; x++){
      //segmentation fault @ i=14 & x=0
      if(strcmp(temp,*(a+x))==0){
	(hist+i)->freq++;
      }
      //printf("2nd for %d\n",x);
    }
    
  }
  
  */
  *arr = hist;

  return uC;
}
void displayHistogram(Histogram arr[], int c){
  
  //printf("%d\n",c);
  for(int i = 0; i<c; i++){
    printf("Value %s: freq %d\n",(arr+i)->wrd,(arr+i)->freq);
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
	char* tempN = (arr+j)->wrd;
	(arr+j)->freq = (arr+j+1)->freq;
	(arr+j)->wrd = (arr+j+1)->wrd;
       	(arr+j+1)->freq = tempF;
	(arr+j+1)->wrd = tempN;
      }
    }
  }
}
