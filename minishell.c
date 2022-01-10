#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
void parseArgs(char* buffer, char** args, int argsSize, int* nargs){
  char* bufArgs[argsSize];
  char** cp;
  char* wbuf;
  int i;
  int j;

  wbuf = buffer;
  bufArgs[0] = buffer;
  args[0] = buffer;
  
  for(cp = bufArgs; (*cp=strsep(&wbuf, " \n\t")) != NULL;){
    if((*cp != '\0') && (++cp >= &bufArgs[argsSize])){
      //printf("Break\n");
      break;
    }
  }
  
  for(j = i = 0; bufArgs[i] != NULL; i++){
    if(strlen(bufArgs[i]) > 0){
      //printf("Copying\n");
      args[j++] = bufArgs[i];
    }
    //printf("%d\n",i);
  }
  
  //Add the NULL as the end argument because we need that for later
  *nargs = j;
  //printf("TEST\n"); //Faults here
  args[j] = NULL;
  
}
char* input(char* args[], int* n){
  int i = 0;
  int b = 0;
  int tempN;
  char* out = NULL;
  //printf("%d\n",n);
  while(i<*n){
    //file = NULL;
    if(strcmp(args[i],"<") == 0){
      //printf("Found < @ %d\n",i);
      char* t = (char*)malloc((strlen(args[i+1])+1)*sizeof(char));
      
      t = strcpy(t,args[i+1]);
            
      for(int l = 0; l<2; l++){
	for(int j = i; j<*n; j++){
	  args[j] = args[j+1];
	  // printf("%d\n",j);
	}
      }
      *n -= 2;
      /*
      printf("Output Method: ");
      for(int x = 0; x<*n; x++){
	printf("%s ",args[x]);
      }
      printf("\n");
      //printf("%s | %s\n",t, args[i+1]); 
      */
      out = t;
    }
    i++;
    //printf("%d\n",i);
  }
  
  return out;
}
char* output(char* args[], int* n){
  int i = 0;
  int b = 0;
  int tempN;
  char* out = NULL;
  //printf("%d\n",n);
  while(i<*n){
    //file = NULL;
    if(strcmp(args[i],">") == 0){
      //printf("Found > @ %d\n",i);
      char* t = (char*)malloc((strlen(args[i+1])+1)*sizeof(char));
      
      t = strcpy(t,args[i+1]);
            
      for(int l = 0; l<2; l++){
	for(int j = i; j<*n; j++){
	  args[j] = args[j+1];
	  // printf("%d\n",j);
	}
      }
      *n -= 2;
      /*
      printf("Output Method: ");
      for(int x = 0; x<*n; x++){
	printf("%s ",args[x]);
      }
      printf("\n");
      //printf("%s | %s\n",t, args[i+1]); 
      */
      out = t;
    }
    i++;
    //printf("%d\n",i);
  }
  
  return out;
}
void handler(int sig){
  //printf("Handler\n");
  //printf("Child with pid: %d died with status: %d\n",pid,status);
  
  int b = 0;
  while(1){
    int status;
    int pid = waitpid(-1,&status,WNOHANG);
    //printf("%d\n",pid);
    if(pid == -1 || pid == 0){
      //printf("HERE\n");
      b = 1;
      //exit(0);
      //kill(pid,sig);
      break;
      
    }
    else{
      //printf("Child with pid: %d died with status: %d\n",pid,status);
    }
  }
  
}
void test(){
  //printf("Sleeping...\n");
  sleep(5);
  int sum = 0;
  /*
  for(int i = 0; i<100; i++){
    printf("%d ",i);
    sum += i;
  }
  printf("Sum: %d\n",sum);
  */
}

int main(){
  
  char* buf = (char*)malloc(PATH_MAX*sizeof(char));
  char scan[256];// = (char*)malloc(PATH_MAX*sizeof(char));
  char *out = getcwd(buf,PATH_MAX);
  //printf("%s>",out);
  
  int b = 0;
  while(b != 1){
 // for(int x = 0; x<5; x++){

    out = getcwd(buf,PATH_MAX);
    printf("%s>",out);

    //scan = fgets(buf,PATH_MAX,stdin);
    int n;
    fgets(scan,PATH_MAX,stdin);
    //printf("%s\n",scan);
    char* args[256];
    //char* buffer = fgets(buf,PATH_MAX,stdin);
    //printf("%s\n", scan);
    parseArgs(scan, args, 256, &n);
    //printf("Parsed: %s, %d\n", args[1],n);

    char* file;
    FILE* fp;
    if(strcmp(args[0],"exit") == 0){
      b = 1;
      //printf("Exiting...\n");
      exit(0);
    }
    else if(strcmp(args[0],"cd") == 0){
      //printf("Changing Directory...\n");
      chdir(args[1]);
    }
    else{
      int and = 0;
      signal(SIGCHLD,handler);
      int pid = fork();
      if(pid != 0){
	int status;
	//printf("In Parent\n");
	if(strcmp(args[n-1],"&") == 0){
	  //printf("Found &\n");
	  //args[n-1] = args[n];
	  and = 1;
	  //int result = waitpid(pid,&status,WNOHANG);
	}
	else{
	  int result = waitpid(pid,&status,0);
	}	
      }
      else{
	//printf("In Child: %d\n", pid);
	
	if(strcmp(args[n-1],"&") == 0){
	  //printf("Theres an &\n");
	  //printf("%s\n", args[n-1]);
	  args[n-1] = args[n];
	  n--;
	  //printf("Removed &: %s\n",args[n-1]);
	}
	/*
	printf("After Removing\n");
	for(int i = 0; i<n; i++){
	  printf("%s ",args[i]);
	}
	printf("\n");
	*/
	if((file = input(args,&n)) != NULL){
	  //printf("\tInput Child: %d\n",n);
	  fp = freopen(file,"r",stdin);
	  /*
	  for(int i = 0; i<n; i++){
	    printf("%s ",args[i]);
	  }
	  printf("\n");
	  */
	  if((file = output(args,&n)) != NULL){
	    fp = freopen(file,"w",stdout);
	  }
	  int rc = execvp(args[0], args);
	}
       
	else if((file = output(args,&n)) != NULL){
	  //printf("\tOutput Child: %d\n", n);
	  fp = freopen(file,"w",stdout);
	  /*
	  for(int i = 0; i<n; i++){
	    printf("%s ",args[i]);
	  }
	  printf("\n");
	  */
	  if((file = input(args,&n)) != NULL){
	    fp = freopen(file,"r",stdin);
	  }
	  int rc = execvp(args[0], args);
	}
	else if(strcmp(args[0],"sleep") == 0){
	  //printf("Sleep\n");
	  test();
	}
	else{
	  //printf("else\n");
	  int rc = execvp(args[0],args);
	}
	//printf("End of Child\n");
      	return 0;
	}
    }

    
       
  }
  
  return 0;
}
