#include <stdio.h>

void qsort(int arr[], int left, int right);
void swap(int arr[], int i, int j);


//////////////////////////////////////////////////
int main(void){

  
  return 0;


}


//////////////////////////////////////////////////
void qsort(int arr[], int left, int right){

  int i, last;

  if(left>=right)
    return;

  int partition = (left + right) / 2;
  swap(arr, left, partition);  // here, essentially just create a 'space' for value storage

  last = left;
  for(i = last + 1; i <= right; i++)
    if(arr[i] < arr[left])
      swap(arr, ++last, i);

  swap(arr, left, last);  // we need to swap the 'last' index with left to maintain strict order
  qsort(arr, left, last-1);
  qsort(arr, last+1, right);
  
}


//////////////////////////////////////////////////
void swap(int arr[], int i, int j){

  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;

}
