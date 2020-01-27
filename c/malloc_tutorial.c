#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////
typedef struct simpleVector{

  int e0, e1;

} simpleVector;


//////////////////////////////////////////////////
typedef struct vector{

  int elements[2];

} vector;


//////////////////////////////////////////////////
int main(){

  // basic understanding of pointers and addresses
  /*
    the pointer notation is as follows <datatype> * var_name
    -> creates a pointer to a block of memory of sizeof(<datatype>)

    the address notation is as follows &var_name
    -> gets the address for an already allocated variable in memory
   */
  int* pNumberOfVectors;
  int numberOfVectors;
  pNumberOfVectors = &numberOfVectors;
  printf("Input an int \n");
  scanf("%d", &numberOfVectors);
  printf("Going to allocate memory for %d vectors \n", numberOfVectors);
  printf("This should also be the number of vectors %d \n", *pNumberOfVectors);

  // dynamic memory allocation
  /* vector* pVectors; */
  /* pVectors = (vector *) malloc(numberOfVectors * sizeof(vector)); */

  simpleVector* pVectors;
  pVectors = (simpleVector *) malloc(numberOfVectors * sizeof(simpleVector));

  printf("Address of pre-allocared vector structs %p \n", pVectors);
  printf("What is the size of one vector? %d \n", sizeof(simpleVector));
  printf("What is the size of the thing that pVectors points to? %d \n", sizeof(*pVectors));

  pVectors->e0 = 0;
  pVectors->e1 = 1;
  printf("Struct 0, element 0 %d \n", pVectors->e0);
  printf("Struct 0, element 1 %d \n", pVectors->e1);

  pVectors++;
  pVectors->e0 = 1;
  pVectors->e1 = 0;
  printf("Struct 1, element 0 %d \n", pVectors->e0);
  printf("Struct 1, element 1 %d \n", pVectors->e1);

  printf("Size of de-referenced' %d \n", sizeof(*pVectors));
  printf("Size of reference-of 'vector' %d \n", sizeof(&pVectors));

  return 0; 

}
