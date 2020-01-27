#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//////////////////////////////////////////////////
int * convert_base(unsigned int numberToConvert, int base, int * result){
  
  // error states
  if (base < 2 || base > 16){
    
    exit(1);

  }  

  int * final_element = result;

  do {

    *result  = numberToConvert % base;
    assert(*result<=16 & *result>=0);
    numberToConvert /= base;

    printf("Converting element [%d] -> address [%p] \n", *result, result);    
    final_element = result;
    ++result;

  } while (numberToConvert != 0);

  return final_element;

}


//////////////////////////////////////////////////
int main(){
  

  // control
  unsigned int number = 9;
  int base = 16;
  int lenResult = 32;

  // define possible values for conversion
  char possibleCharacters[] = "0123456789ABCDEF";

  // can also use sizeof(int) == sizeof(int *)
  int * pConvertedNumber;
  pConvertedNumber = (int *) malloc(sizeof(int) * lenResult);
  int** tracker = &pConvertedNumber;

  // tracker is used to keep check of "result" position in memory
  for(int i=0; i<=lenResult; i++){

    printf("%d \n", *(*tracker+i));
    printf("%p \n", (*tracker)+i);
    printf("%p \n", (tracker)+i);

  }

  // perform conversion
  int * result_index = convert_base(number, base, pConvertedNumber);
  printf("This is the address after pointer is manipulated %p \n", pConvertedNumber);

  do {

    printf("element [%p] -> [%c] address [%d] \n", result_index, possibleCharacters[*result_index], *result_index);
    result_index--;

  } while(result_index >= pConvertedNumber);

  free(pConvertedNumber);
  return 0;

}
