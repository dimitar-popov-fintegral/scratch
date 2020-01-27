#include <stdio.h>
#include <stdlib.h>  // contains mathematical functions for int-types
#include <string.h>  // contains the strlen(char[]) function
#define MAX 100

void printd(int n);
void itoa_rec(int, char[]);
void myreverse(char[]);
void swap(char[], int, int);
void true_reverse(char arr[]);


//////////////////////////////////////////////////
int main(void){

  char arr[] = "ReverseMeInplace!";
  myreverse(arr);
  printf("Result [%s] \n", arr);

  true_reverse(arr);
  printf("Result [%s] \n", arr);

  return 0;

}


//////////////////////////////////////////////////
void itoa_rec(int n, char arr[]){
 
  static int counter;

  if(n/10){
    itoa_rec(n/10, arr);
  }
  else{
    counter = 0;
    if(n<0)
      arr[counter++] = '-';
    else
      arr[counter++] = '+';
  }

  arr[counter++] = abs(n) % 10 + '0';
  arr[counter] = '\0';

  /* printf("putting [%c] into pos [%d] \n", n%10+'0', counter); */
  /* arr[counter] = n % 10 + '0'; */

}


//////////////////////////////////////////////////
void printd(int n){

  if(n<0){
    putchar('-');
    n *= -1;
  }

  if(n/10)
    printd(n/10);

  putchar(n%10+'0');
}


//////////////////////////////////////////////////
void true_reverse(char arr[]){
  
  void reverser(char[], int, int);
  reverser(arr, 0, strlen(arr));
  
}


//////////////////////////////////////////////////
void reverser(char arr[], int i, int len){

  int j = len - (i + 1);
  if(i<j){
    swap(arr, i, j);
    reverser(arr, ++i, len);
  }


}


//////////////////////////////////////////////////
void myreverse(char arr[]){
    
  static int i=0;
  static int j=0;
  static int end=0;

  if(i==0){
    while(arr[i++]!='\0')
      ;
    end=--i;
  }
  else if(i>end/2){
    swap(arr, --i, j++);
    printf("swapped i=[%d] <-> j=[%d] \n", i,j);
  }
  else
    return;
      
  myreverse(arr);

}


//////////////////////////////////////////////////
void swap(char arr[], int i, int j){

  char temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;

}
