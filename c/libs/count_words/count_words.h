#include <stdio.h>
#include <string.h>

struct key{

  char * word;
  int count;

} key_arr[] = {
	     {"include", 0},
	     {"define", 0},
	     {"struct", 0},
	     {"int", 0}
};

void quick_sort(void * arr[], int left, int right,
		int (* comp)(void *, void * ));

int kw_comp(const struct key * left, const struct key * right);
int count_comp(const struct key * left, const struct key * right);

