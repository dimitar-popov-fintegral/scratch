#include <count_words.h>


//////////////////////////////////////////////////
void quick_sort(void * arr[], int left, int right,
		int (* comp)(void *, void *)){

  /*
    1. check for trivial/error case, or one obj only
    2. partition into, typically two sides
    3. swap split element & left-most item i.e. create hole
    4. start loop
      . last = hole
      . compare lhs, rhs
      . swap if lhs < rhs
      . increment after swap 
  */
  int i, hole, partition;

  if(left>=right)
    return;

  partition = (left + right) / 2;
  swap(arr, left, partition);
  hole = left;
  for(i = hole + 1; i <= right; i++)
    if(comp((void *) arr[i], (void *) arr[left]) < 0)
       swap((void **) arr, ++hole, i);

  swap((void **) arr, left, hole);
  quick_sort(arr, left, hole - 1, comp);
  quick_sort(arr, hole + 1, right, comp);

  return;

}


//////////////////////////////////////////////////
void swap(void * arr[], int i, int j){

  if(i==j)
    return;

  void * temp = arr[j];
  arr[j] = arr[i];
  arr[i] = temp;

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

