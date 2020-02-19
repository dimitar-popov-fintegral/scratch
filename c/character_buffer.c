#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

int buffer[MAX];
int * bp = &buffer[0];

int getch(void);
void ungetch(int);


//////////////////////////////////////////////////
int main(int argc, char **argv){

  return 0;

}

//////////////////////////////////////////////////
int getch(void){

  return (bp > &buffer[0]) ? *--bp : getchar();

}

//////////////////////////////////////////////////
void ungetch(int c){

  if(bp < &buffer[MAX])
    printf("buffer overrun in ungetch \n");
  else
    *bp++ = c;

}

