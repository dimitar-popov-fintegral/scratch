#include <stdlib.h>
#include <stdio.h>

int binary_search(int x, int vector[], int n);

int main(){

  int test[] = {1,3,5,7,11,13,17,19};
  int vector_size = sizeof(test) / sizeof(int);
  int x = 5;
  printf("Should return 2, returns [%d] \n", binary_search(x, test, vector_size));

  x = 4;
  printf("Should return -1, returns [%d]\n", binary_search(x, test, vector_size));
  
  return 0;

}

/*
 * Function: binary_search
 * ------------------------------------------
 * sorted array :param vector: is searched for
 * the element :param x:
 * the size of array is given by :param n:
 */
int binary_search(int x, int vector[], int vector_size){

  int low, mid, high;

  low = 0;
  high = vector_size - 1;
  
  while(low <= high){
    
    mid = (high + low) / 2;
    printf("low [%d], mid [%d], high [%d] \n", low, mid, high);
    if(x < vector[mid]) // the value may exist in lower half
      high = mid + 1;
    else if(x > vector[mid]) // the value may exist in upper half
      low = mid + 1;
    else // the match is the middle value
      return mid;
  }

  return -1; // match not found

}
