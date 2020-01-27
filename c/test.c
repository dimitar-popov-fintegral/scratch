#include <stdio.h>

int main(){

  int MAX = 10;
  int arr1[MAX];
  int * p = arr1;
  int n = 7;
  int * last = &arr1[MAX];

  // "allocate" some memory first
  p=p+2;

  // check if we can "allocate" more
  if(last - (p+n) > 0)
    printf("Yes!\n");
  else
    printf("No!\n");

  return 0;

}
