#include <stdio.h>

#define BUFFERSIZE 100

static int bufp = 0;  // next free buffer position 
static char buffer[BUFFERSIZE];  // buffer itself


//////////////////////////////////////////////////
int getch(void){

  return (bufp > 0) ? buffer[--bufp] : getchar();

}


//////////////////////////////////////////////////
void ungetch(int c){

  if(bufp>=BUFFERSIZE)
    printf("Buffer for [ungetch] of size [%d] caught too many characters", BUFFERSIZE);
  else
    buffer[bufp++] = c;

}


