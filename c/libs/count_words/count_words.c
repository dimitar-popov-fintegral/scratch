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
int __bsearch(void * item, void * arr[],
	      int (* comp)(void *, void *), int n){
  int min = 0;
  int max = n - 1;
  int mid, cond;

  static int here = 0;
  printf("here [%d]\n", here);

  while(min <= max){
    
    printf("min [%d]\n", min);
    printf("max [%d]\n", max);

    // if cond = compare(word, table[mid].word) < 0 --> max = mid - 1
    // elif cond > 0 --> min = mid + 1
    // else cond == 0 --> return mid

    mid = (min + max) / 2;
    printf("this is the mid [%d]\n", mid);
    print_key(item);
    print_key(arr[mid]);


    printf("condition [%d]", cond);
    if((cond = comp((void *) item, (void *) arr[mid])) < 0)
      max = mid - 1;
    else if(cond > 0)
      min = mid + 1;
    else
      return mid;
  }
  return -1;

}


//////////////////////////////////////////////////
void print_key(struct key * itm){
  printf("::print_key::key:[%s] - val:[%d]\n", itm->word, itm->count);
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

