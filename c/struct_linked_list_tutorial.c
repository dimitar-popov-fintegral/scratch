#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////
struct vector{

  int e0, e1;
  struct vector* next;

};


//////////////////////////////////////////////////
struct tensor{

  struct vector v1, v2, v3;

};


//////////////////////////////////////////////////
void read_to_stdout(FILE* stream){

  int maxLineLength = 1024;
  char line[maxLineLength];

  while(fgets(line, maxLineLength, stream)){

    printf("Got the following line from stream-reader: [%s] \n", line);
    
  }

}


//////////////////////////////////////////////////
struct vector* create_vector(struct vector* current, int e0, int e1, struct vector* next){

  current->e0 = e0;
  current->e1 = e1;
  current->next = next;
  return current;

}


//////////////////////////////////////////////////
void print_vector(struct vector* vector){

  printf("Element0 [%d], Element1 [%d] \n", vector->e0, vector->e1);

}


//////////////////////////////////////////////////
void remove_vector(struct vector* vector){

  if(vector->next == NULL){
    
    printf("Removing last item from linked list, \n");
    
  }


}



//////////////////////////////////////////////////
int main(){

  // reading simple input from .csv/.txt files
  FILE* stream = fopen("tensor_dimensions.csv", "r");
  read_to_stdout(stream);

  // linked list from vectors
  int numberOfVectors;
  printf("Number of vectors to allocate memory for? \n");
  scanf("%d", &numberOfVectors);
  printf("Allocating memory for [%d] vector(s) \n", numberOfVectors);
  struct vector* pVectors;
  pVectors = (struct vector *) malloc(numberOfVectors * sizeof(struct vector));
  
  // operations on linked list of vectors
  struct vector* v0 = create_vector(pVectors, 1, 0, NULL);
  struct vector* v1 = create_vector(pVectors++, 0, 1, NULL);
  struct vector* v2 = create_vector(pVectors++, 1, 1, NULL);

  struct vector* initNode = pVector;

  v0->next = v1;
  v1->next = v2;
  v2->next = NULL;

  printf("First \n");
  print_vector(v0);

  printf("Second \n");
  print_vector(v1);

  printf("Third \n");
  print_vector(v2);

  return 0;

  // remove item from linked list -> v1
  remove_item();


}
