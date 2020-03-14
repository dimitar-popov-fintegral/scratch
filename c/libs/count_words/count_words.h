#include <stdio.h>
#include <string.h>

struct key{

  char * word;
  int count;

};

void quick_sort(void * arr[], int left, int right,
		int (* comp)(void *, void * ));
void swap(void * arr[], int left, int right);
int kw_comp(const struct key * left, const struct key * right);
int count_comp(const struct key * left, const struct key * right);

