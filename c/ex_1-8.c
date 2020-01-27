#include <stdio.h>

int main(){

  /*
    program to transform input of arbitrary spaces -> single space

    example: 
        abc    abc    \n -> abc abc \n

   */

  int c;
  int condition = 0;

  for(c; (c=getchar()) != EOF; ++c){

    if(c != ' '){
      putchar(c);
      condition = 0;
    }
    else{
      if(condition)
	putchar('\0');
      else{
	putchar(' ');
	condition = 1;
      }
    }
  }

  printf("Value of c = [%d] \n", c);
  return 0;

}
