#include <stdio.h>

int main(){

  int c;
  int tab=0, bckspc=0, bckslsh=0;

  for(c; (c=getchar()) != EOF; ++c){
    
    if(c == '\t'){
      putchar('\\');
      putchar('t');
    }
    else if(c == '\b'){
      putchar('\\');
      putchar('b');
    }
    else if(c == '\\'){
      putchar('\\');
      putchar('\\');
    }
    else
      putchar(c);
  }

  printf("Value of c = [%d] \n", c);
  return 0;

}
