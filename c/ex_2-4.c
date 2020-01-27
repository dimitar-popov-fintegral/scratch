#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

void squeeze2(char s[], char c[]);


////////////////////////////////////////
int main(){

  char test[] = "A good day to be alive!";
  char rem[] = " o";

  printf("Original [%s] \n", test);
  squeeze2(test, rem);
  printf("Result [%s] \n", test);

  return 0;

}


void squeeze2(char s[], char t[]){

  int i,j,k;
  int r;
  for(k=0; (r = t[k]) != '\0'; ++k){

    for(i = j = 0; s[i] != '\0'; ++i){

      if(s[i] != r)
	s[j++] = s[i];

    }
    s[j] = '\0';
  }

}

