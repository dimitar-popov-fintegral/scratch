#include <stdio.h>
#include <assert.h>
#include "calc.h"

#define MAXVAL 100

int sp = 0;  // this is the position to next free space on stack
double val[MAXVAL];  // this is the stack for numbers


//////////////////////////////////////////////////
void push(double e){

  if(sp<MAXVAL)
    val[sp++] = e;
  else
    printf("Stack of size [%d] is full, cannot append [%f]", MAXVAL, e);

}


//////////////////////////////////////////////////
double pop(void){
  
  assert(sp>0);
  return val[--sp];

}

