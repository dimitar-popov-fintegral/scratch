#include <stdio.h>

#define MAX 1000

// this is a function prototype
// it allows you to declare functions before the main
int getline2(char s[], int m);
void copy(char from[], char to[]);

int main(){

  int len, maxLen;
  char line[MAX], store[MAX];

  len = maxLen = 0;

  while((len = getline2(line, MAX)) > 0){
    if(len>maxLen){
      maxLen = len;
      copy(line, store);
    }
    
  }

  for(int j=0; j<maxLen; ++j)
    putchar(store[j]);

  printf("This is an alternative method of string display \n [%s] \n", store);

  return 0;

}

void copy(char from[], char to[]){
  
  int i = 0;
  while((to[i] = from[i]) != '\0')
    ++i;

}


// arrays are special in C
// they are always passed as reference i.e. pointers
// this means that a pointer to their first element is always passed
// below function operates on 'line[]' in-place
int getline2(char line[], int maxLine){

  int c,i;

  for(i=0; i<maxLine-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;

  if(c == '\n'){
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return i;

}
