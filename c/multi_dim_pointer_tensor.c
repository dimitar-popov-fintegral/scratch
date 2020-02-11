#include <stdio.h>
#define MAX 1000

typedef struct{

  char *arr[MAX];

} Tensor;


int main(){

  Tensor * tensor[MAX];
  printf("the tensor is of size, [%d]\n", sizeof(tensor));

  return 0;

}

