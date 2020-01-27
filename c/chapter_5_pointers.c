#include <stdio.h>
#include <ctype.h>
#include "./reverse_polish_calc/getch.c"
#define MAX 10

extern int getch(void);
extern void ungetch(int);
int getint(int * p);


//////////////////////////////////////////////////
int main(){

  int a[2];
  int * pi;
  pi = a;
  printf("%p, %p \n", ++pi, a);
  *pi = 1;
  *a = 0;
  printf("[%p] -> %d, [%p] -> %d \n", pi, *pi, a, *a);

  int arr[MAX];
  int i;
  int * p = &i;

  for(i=0; i<MAX && getint(&arr[i]) != EOF; i++)
    ;
  
  printf("got [%d] ints \n", *p);

  for(int j=0; j<*p; j++)
    printf("%d", arr[j]);

  return 0;

}


//////////////////////////////////////////////////
int getint(int * p){

  int c, sign;

  while(isspace(c=getch()))
    ;

  if(!isdigit(c) && c!=EOF && c != '+' && c!= '-'){
    printf("This is not a digit [%c] \n", c);
    return 0;
  }

  sign = (c == '-') ? -1 : 1;

  if(c == '-' || c == '+')
    c = getch();

  for(*p=0; isdigit(c); c = getch())
    *p = 10 * *p + (c - '0');

  *p *= sign;

  if(c != EOF)
    ungetch(c);

  return c;

}  
