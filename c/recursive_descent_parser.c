#include <stdio.h>

void dcl(void);
void dirdcl(void);

int main(int argc, char **arg){

  return 0;

}

void dcl(void){

  int num_stars;

  /* simple counting of start characters */
  for(num_stars = 0; gettoken() == '*'; )
    num_stars++;

  /* function is called recursively, i.e. within dirdcl, 
   a call to dcl is made*/
  dirdcl();

  /* appends to the out string that something is a pointer 
   to ... */
  while(num_stars-- > 0)
    strcat(out, " pointer to");

}


void dirdcl(void){

  /* found a type of dir-dcl which is (dcl) */
  if(tokentype == '('){

    dcl();
    if(tokentype != ')')
      printf("error: missing a matchin ')' character \n");
    /* found a type of dir-dcl which is NAME */

  } else if(tokentype == NAME){

    strcat(out, token);

  } else
    printf("error: expecting (dcl) or NAME \n");

  while((type == gettoken) == PARENS || type == BRACKETS){

    if(type == PARENS)
      strcat(out, " function returning");
    else{

      strcat(out, "array");
      strcat(out, token);
      strcat(out, " of")
    }

  }

}
