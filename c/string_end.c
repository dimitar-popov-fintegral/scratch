#include <stdio.h>
#include <assert.h>

int send(char *, char *);
size_t slen();

//////////////////////////////////////////////////
int main(){

  char s[] = "butterfly";
  char t[] = "fly";
  char u[] = "bly";

  assert(send(s,t) == 1); 
  assert(send(s,u) == 0);

  return 0;

}


//////////////////////////////////////////////////
size_t slen(char * s){

  size_t n = 0;
  while(*s++ != '\0')
    n++;

  return n;

}


//////////////////////////////////////////////////
int send(char * s, char * t){

  int match = 0;
  int len_s, len_t;

  if( (len_s = slen(s)) < (len_t = slen(t)))
    return 0;

  // point to end of string
  while(*s)
    s++;

  while(*t)
    t++;

  while(*s-- == *t--){
    match++;
  }

  if(match == len_t+1)
    return 1;

  return 0;

}
