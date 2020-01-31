#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void scat(char *, char *);
size_t slen(char *);
void swap(char ** s, char ** t);
void scpy(char *, char *);

/*
  @DP
  just a note on the solution to this problem
  none of the functions really check for buffer overrun 
  I was not able to think of a clever solution which fits the 
  prototype i.e. void returning function which takes two 
  pointer args
 */

//////////////////////////////////////////////////
int main(){
  
  // show how one can swap where a pointer is pointing to
  char arr[] = "text";
  char ** pptr;
  char * ptr;
  char ** elsewhere;
  ptr = arr;
  pptr = &ptr;
  printf("mem. location of arr [%p] \n", arr);
  printf("mem. location of pptr [%p] \n", pptr);

  printf("*pptr = [%p] \n", *pptr);
  printf("*elsewhere = [%p] \n", *elsewhere);  
  swap(pptr, elsewhere);
  printf("*pptr = [%p] \n", *pptr);
  printf("*elsewhere = [%p] \n", *elsewhere);  

  // concat two strings 'safely'
  char left[MAX] = "nastya ";
  char right[] = "dim";

  printf("s = [%p] \n", *left);
  scat(left, right);
  printf("result [%s] \n", left);
  return 0;

}


//////////////////////////////////////////////////
void swap(char ** s, char ** t){

  char * temp = *s;
  *s = *t;
  *t = temp;

}


//////////////////////////////////////////////////
size_t slen(char * s){

  size_t n = 0;
  while(*s++ != '\0')
    n++;

  return n;

}


//////////////////////////////////////////////////
void scpy(char * s, char * t){

  while((*s++ = *t++))
    ;

}


//////////////////////////////////////////////////
void scat(char * s, char * t){

  while(*s)
    s++;
  scpy(s,t);
}

