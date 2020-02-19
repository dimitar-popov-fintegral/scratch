#include <stdio.h>

char (*(*x())[])();

int main(int argc, char *argv[]){

  int *data[13];
  printf("size of data is [%li]\n", sizeof(data));
  printf("size of data is [%li]\n", sizeof(data+1));  

  /* this illustrates the declarative difference between
  *++w and *w++ */
  char c;
  char * w = "this";
  while((c=*++w))
    printf("[%c]\n", c);

  return 0;
}
