#include <count_words.h>

//////////////////////////////////////////////////
int main(int argc, char **argv){

  printf("here!\n");
  return 0;

}

//////////////////////////////////////////////////
int kw_comp(const struct key * left, const struct key * right){

  int lhs_vs_rhs = strcmp(left->word, right->word);

  if(lhs_vs_rhs > 0)
    return 1;
  else if(lhs_vs_rhs < 0)
    return -1;
  else
    return 0;

}

//////////////////////////////////////////////////
int count_comp(const struct key * left, const struct key * right){

  int lhs_vs_rhs = left->count - right->count;
  
  if(lhs_vs_rhs > 0)
    return 1;
  else if(lhs_vs_rhs < 0)
    return -1;
  else
    return 0;

}

