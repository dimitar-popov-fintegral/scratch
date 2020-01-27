#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////
struct vector2d{

  int pos0, pos1;

};


//////////////////////////////////////////////////
void setAndReadVec(const struct vector2d vector){

  vector.pos0 = 0;
  vector.pos1 = 1;

  printf("Vector pos0 [%d] pos1 [%d]", vector.pos0, vector.pos1);

}


//////////////////////////////////////////////////
void main(){
  /*
    
    The following program should fail to compile
    - in the definition of 'setAndReadVec' const is used to denote the variable vector
    - this disallows for any modification of the arg vector, in this case a struct
      resembling a vector

    To fix the program, simple remove the 'const'

   */


  struct vector2d vector = {1, 0};

  setAndReadVec(vector);

  printf("Done!");

}
