#include <stdio.h>

int main(int argc, char *argv[]){

  char ** last  = argv + argc - 1;
  while(*argv++)
    printf("%s%s", *argv != NULL ? *argv: "", argv != last ? " ": "");

  printf("\n");
  return 0;

}
