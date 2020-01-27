#include <stdlib.h>
#include <stdio.h>

int count_bits(unsigned int x);


int main(){

  /*
   * in a 2's complement machine x &= (x-1)
   * deletes the right-most 1-bit in x
   */

  // 0000 1000 0000 0000 -> unsigned int a = 2048;
  // 0000 0111 1111 1111 -> = 2048 - 1
  // 0000 0000 0000 0000 -> 0

  // 0000 0000 0000 0011 -> unsigned int b = 3;
  // 0000 0000 0000 0010 -> = 3 - 1
  // 0000 0000 0000 0010 -> 2

  int test = 2047;
  int count = count_bits(test);
  printf("original [%d] which contains [%d] 1-bits", test, count);
  return 0;
}

int count_bits(unsigned int x){

  int count=0;
  while(x != 0){
    x &= (x-1);
    ++count;
  }
  return count;
}
