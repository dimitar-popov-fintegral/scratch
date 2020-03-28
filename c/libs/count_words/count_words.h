#include <stdio.h>
#include <string.h>

struct key{

  char * word;
  int count;

};

/* Function prototypes */

//////////////////////////////////////////////////
void quick_sort(void * arr[], int left, int right,
		int (* comp)(void *, void * ));


//////////////////////////////////////////////////
int __bsearch(void * item, void * arr[],
		  int (* comp)(void *, void *), int n);


//////////////////////////////////////////////////
void print_key(struct key *);


//////////////////////////////////////////////////
void swap(void * arr[], int left, int right);


//////////////////////////////////////////////////
int kw_comp(const struct key * left, const struct key * right);


//////////////////////////////////////////////////
int count_comp(const struct key * left, const struct key * right);

