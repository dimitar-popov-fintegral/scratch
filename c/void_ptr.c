#include <stdio.h>
#include <stdlib.h>

void swap(void *arr[], int i, int j);

int main(int argc, char *argv[]){

  int i = 0;
  char * p;
  if(argc >= 2){
    swap(argv, 2, 1);
    while((p = *++argv))
      printf("arg [%d] = [%s] \n", i++, p);

  }
  else
    exit(0);

  return 0;

}


void swap(void *arr[], int i, int j){

  void * temp;
  temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;  

}
