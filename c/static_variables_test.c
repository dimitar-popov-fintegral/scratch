#include <stdio.h>

void f(int);

//////////////////////////////////////////////////
int main(void){

  for(int i = 0; i < 10; i++)
    f(i);

  return 0;

}


//////////////////////////////////////////////////
void f(int e){

  static int c = 0;

  printf("This is the value at start [%d] \n", c);
  printf("This is the value after manipulation [%d] \n", (c = e));
  printf("Done! \n");

}
