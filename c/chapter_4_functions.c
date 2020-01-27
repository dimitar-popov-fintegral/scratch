#include <stdio.h>

int strindex(char str[], char match[]);



//////////////////////////////////////////////////
int main(){

  char test[] = "this is actually a test test test str";
  char match[] = "test";

  printf("Result of str-search [%d] \n", strindex(test, match));

  return 0;

}


/*
 * Function: strindex
 * ----------------------------------------
 * Purpose of this function is to seek out the first
 * occurance of :param match: in :param str:
 * returns -1 if no match is found
 */
int strindex(char str[], char match[]){

  int j,k;

  //outer loop: goes over the str array
  for(int i=0; str[i] != '\0'; i++){
    //inner loop: goes over potential matches one char at a time
    for(j=i, k=0; match[k] != '\0' && str[j] == match[k]; j++, k++)
      ;
    //important to make sure that the we go over all values of match
    // i.e. by using the condition match[k] == '\0'
    if(k>0 && match[k] == '\0'){
      return i;
    }
  }
  
  return -1;

}
