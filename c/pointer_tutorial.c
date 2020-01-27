#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//////////////////////////////////////////////////
typedef struct vector{

  int rowVector[2];

} vector;


//////////////////////////////////////////////////
typedef struct matrix{

  vector firstRow;
  vector SecondRow;
  
} matrix;


//////////////////////////////////////////////////
int getArrayLength(int *array){
  
  assert(sizeof(array)>0);
  return sizeof(array) / sizeof(array[0]);
    
}


//////////////////////////////////////////////////
void printVector(vector vec){

  int length = getArrayLength(vec.rowVector);
  for(int i=0; i<length; i++){
    printf("element %d equals %d  \n", i, vec.rowVector[i]);
  }
  
}


//////////////////////////////////////////////////
int main(){

  //create a pointer array for storing strings
  char * models[4] = {"BETA", "GAC", "LASSO"};

  for(int i=0; i < 3; i++){
    
    printf("Model %s : reference %p \n", models[i], &models[i]);

  }

  vector firstRow = {{0,1}};
  vector secondRow = {{1,0}};

  printVector(firstRow);
  printVector(secondRow);

  matrix eye2 = {firstRow, secondRow};

  return 0;

}
