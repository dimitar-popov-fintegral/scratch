/*
 building a stack to allocated/deallocate 
 memory to the program
 ----------------------------------------
 the basic idea for the stack-based 
 implementation is:

 1. Have an allocation buffer from which
    we freely "hand-out" storage 
 2. A function char * alloc(int n) 
 3. A function void afree(char *p)
 */

#include <stdio.h>
#define MAX 10000

char * alloc(int);
void afree(char *);

static char allocbuffer[MAX];
static char * allocp = allocbuffer;
static char * last = allocbuffer + MAX;

//////////////////////////////////////////////////
char * alloc(int n){

  if(last - allocp >= n){
    allocp += n;
    return allocp - n;
  }
  else{
    printf("not enugh memory in buffer to allocate");
    return NULL;
  }

}


//////////////////////////////////////////////////
void afree(char * p){

  if(p >= allocbuffer && p < allocbuffer + MAX)
    allocp = p;

}
