#include <stdio.h>
#include <ctype.h>
#include "calc.h"

extern int getch(void);
extern void ungetch(int);
int getop(char []);


//////////////////////////////////////////////////
int getop(char arr[]){

  int i, c;
  static int temp = 0;

  if(temp == 0){
    c = getch();
  }
  else{
    c = temp;
    temp = 0;
  }


  // skipping spaces 
  while((arr[0] = c = getch()) == ' ' || c == '\t')
    ;

  // end of operation arr/str - not sure why this is here
  arr[1] = '\0';
  
  // check if part is a digit to be gathered
  if(!isdigit(c) && c != '.'){
    if(c != '\n')
      printf("Returning non-digit value [%c] \n", c);
    return c;
  }

  i = 0;
  // if is digit, harvest stuff before decimal point
  if(isdigit(c))
    while(isdigit(arr[++i] = c = getch()))
      ;

  // ... and stuff after decimal point
  if(c == '.')
    while(isdigit(arr[++i] = c = getch()))
      ;

  // end of arr/str - not sure why this is here either
  arr[i] = '\0';

  // what happens here is that if we don't harvest a number or an op
  // we should ungetch such that we return to state as if input was never read
  if(c != EOF)
    temp = c;

  return NUMBER;

}











