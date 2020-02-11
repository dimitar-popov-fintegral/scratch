#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

  /*
    this version of cmd parsing will only take the first '-'
    char seriously and ignore all cl-args thereafter as NULL
    i.e.
    prog -one two three
    -> o,n,e 
    -> return 0;

    addendum one:
      . improvement, from *++argv[0] -> *++(*argv)
      . this can be done because
      a *argv de-references to a pointer
      b ++(*argv) increments that pointer (a string already)
      c *++(*argv) resolves to a char in that string
  */

  int c;
  while(--argc > 0 && **++argv == '-'){
    while((c = *++(*argv))){
      printf("got [%c] \n", c);
    }
  }
    
  /*
    text explaining wtf 
  */
  
  while(--argc > 0 && **++argv == '-')
    while((c = *++(*argv)))
      switch(c){
      case 'o':
	printf("one at a time\n");
      case 'n':
	printf("no entry int house\n");
      case 'e':
	printf("endmode on\n");
      case 'm':
	printf("marshmellows\n");
      default:
	exit(-1);
      }

  return 0; 

}
