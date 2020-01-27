#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100

// function <<myfunciton>> not visible outside of main.c
// i.e. is private
static int myfunction(void);


//////////////////////////////////////////////////
int main(void){

  double temp;
  int type;
  char opbuf[MAXOP];

  while((type = getop(opbuf)) != EOF){
    switch(type){
      case NUMBER:
	push(atof(opbuf));
	break;
      case '+':
	push(pop() + pop());
	break;
      case '*':
	push(pop() * pop());
	break;
      case '-':
	push(-pop() + pop());
	break;
      case '/':
	temp = pop();
	if(temp != 0.0)
	  push((pop() / temp));
	else{
	  printf("zero-divisor not allowed \n");
	  printf("discarding [%f] \n", pop());
	}
	break;
      case '\n':
	printf("this line is pop'd [%.8g] \n", pop());
	break;
      default:
	printf("error: unknown command [%s] \n", opbuf);
    }
  }

  return 0;

}
