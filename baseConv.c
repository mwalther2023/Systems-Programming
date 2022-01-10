#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binToDec(char* bin);
char* decToBin(int dec);
int baseToDec(int base, char* value);
char* decToBase(int base, int dec);

int main(){
  int num = binToDec("11001");
  char* bin = decToBin(num);

  printf("Dec: %d\nBin: %s\n",num,bin);

  //int d = baseToDec(8,"157");
  int d = baseToDec(16,"f8");
  char* b = decToBase(16, d);
  printf("%d, %s\n",d,b);
}
int baseToDec(int base, char* value){
  int size = strlen(value);
  int num = 0;
  int pt = 0;
  if(base<11){
    for(int i = size-1; i>-1; i--){
      int temp = value[i] - 48;
      
      int add = 1;
      for(int x = 0; x<pt; x++){
	add *= base;
      }
      
      num += temp*add;
      //printf("%d, %d\n", num,temp);
      pt++;
    }
  }
  else{
    for(int i = size-1; i>-1; i--){
      int add = 1;
      for(int x = 0; x<pt; x++){
	add *= base;
      }
      int temp = 0;
      if(value[i] > 96){
	temp = value[i]-87;
	
      }
      else{
	temp = value[i] - 48;
      }
      num += temp*add;
      pt++;
    }
  }
  return num;
}
char* decToBase(int base, int dec){
  char* out = (char*)malloc(16*sizeof(char));
  int boo = 0;
  int i = 16;
  int add = 1;
  int temp = dec;
  int pt = 0;
  
  while(i>-1 && temp != 0){
    //out[i] = (char)((temp % base) + 48);
    int t = temp%base;
    if(base < 11){
      t += 48;
    }
    else{
      if(t>9){
	t += 87;
      }
      else{
	t += 48;
      }
    }
    out[i] = (char)t;
    //printf("%s\n",out+i);
    temp = temp/base;
    i--;
    pt++;
  }
  
  //printf("%d,%s\n",pt,(out+(17-pt)));
  return out+(17-pt);
}
int binToDec(char* bin){
  int size = strlen(bin);
  //printf("%d\n",size);
  int num = 0;
  int pt = 0;
  for(int i = size-1; i>-1; i--){
    //printf("Bin @ i: %d\n",bin[i]);
    //if(strcmp(bin[i],"1") == 0){
    if(bin[i] == '1'){
      int add = 1;
      for(int x = 0; x<pt; x++){
        add *= 2;
      }
      //printf("Add: %d\n",add);
      num += add;
      pt++;
    }
    //else if(strcmp(bin[i],"0") == 0){
    else if(bin[i] == '0'){
      pt++;
    }
  }
  return num;
}
char* decToBin(int dec){
  char* out = (char*)malloc(16*sizeof(char));
  int boo = 0;
  int i = 0;
  int add = 1;
  int temp = dec;
  //printf("Here\n");
  for(int x = 0; x<17; x++){
    add *= 2;
  }
  
  while(i<32 && boo == 0){
    if((temp-add) >0){
      out[i] = '1';
      temp -= add;
      add = add/2;
    }
    else if((temp-add)==0){
      boo = 1;
      out[i] = '1';
      temp -= add;
      add = add/2;
    }
    else{
      out[i] = '0';
      add = add/2;
    }
    i++;
  }
  int t = 0;
  while(out[t] == '0'){
    t++;
  }
  char* out2 = (out+t);
  free(out);
  return out2;
}
