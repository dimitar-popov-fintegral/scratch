#include <stdio.h>

/*
  write a program to display a histogram of characters 
*/

int main(){

  int total = 0;

  int c;
  int counts[12];

  // should init variables else they might hold trash
  for(int i=0;i<10;++i)
    counts[i]=0;

  // counting of the digits
  while((c = getchar()) != EOF){
    ++total;
    if (c>'0' && c<'9')
      ++counts[c-'0'];
    else if (c == ' ' || c == '\n' || c == '\t')
      ++counts[10];
    else
      ++counts[11];
  }

  int max = 0;
  for(int j=0; j<12; ++j)
    if (counts[j]>max)
      max = counts[j];
      
  printf("Max counts is [%d]", max);

  for(int row=max; row>=0; --row){
    for(int col=0; col<12; ++col){
      
      if (counts[col]>=row)
	putchar('#');
      else
	putchar(' ');
      ++col;

    }
    --row;
    putchar('\n');
    if (row==0)
      printf("0123456789wo");
  }

  return 0;

}
