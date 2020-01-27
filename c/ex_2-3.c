#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int htoi(char s[]);


////////////////////////////////////////
int main(){

  char test[] = "0xABC";
  int res = htoi(test);
  return res;

}


////////////////////////////////////////
int htoi(char s[]){

  int res = 0;
  int i = 0;
  int count = 0;
  int c;

  if((s[0] == '0' && s[1] == 'x') || (s[0] == '0' && s[1] == 'X')){
    i+=2;
  }
    
  for(int j = i; s[j] != '\0'; ++j)
    ++count;

  printf("string length is [%d]\n", count);
  count -= 1;

  while((c = s[i]) != '\0'){
    int c_lower = tolower(c);
    int val = 0;
    if(c_lower >= 'a' && c_lower <= 'f')
      val = c_lower - 'a' + 10;
    else if(c_lower >= '0' && c_lower <= '9')
      val = c_lower - '0';
    else{
      printf("[%c] is not a valid HEX character, aborting", c_lower);
      exit(c_lower);
       
    }

    res += val * pow(16, count--);
    ++i;
  }
	  
  printf("result of converting [%s] to [%d]\n", s, res);

  return res;

}


