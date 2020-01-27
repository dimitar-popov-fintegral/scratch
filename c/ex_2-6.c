#include <stdlib.h>
#include <stdio.h>

unsigned setbits(int x, int p, int n, int y);
unsigned getbits(unsigned x, int p, int n);

////////////////////////////////////////
int main(){

  unsigned test = 2048;
  int p = 11, n = 4;
  unsigned res = getbits(test, p, n);
  printf("original [%d], result [%d] \n", test, res);

  return 0;

}


/*
 * Function: getbits
 * ------------------------------------
 * fetch :param int n: bits from position
 * :param p: 
 * bit position 0 is @ right end of word
 */
unsigned getbits(unsigned x, int p, int n){

  
                                  // 0000 1000 0000 0000
  x >>= (p+1-n);                  // 0000 0000 0000 1000 
  // you have traversed p-bloks, want to carry over n-bloks
  // shift all by moving p+1-n
  // above p=11, n=4
  // shift = p+1-n = 8
    
  int mask = ~0;                  // 1111 1111 1111 1111
  mask = mask << n;               // 1111 1111 1111 0000
  mask = ~mask;                   // 0000 0000 0000 1111

  return x & mask;

}


