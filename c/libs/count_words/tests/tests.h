#include <check.h>
#include "../count_words.h"
 

//////////////////////////////////////////////////
START_TEST (sample_test){
  printf("Running sample test function \n");
  ck_assert_int_eq(42, 42);
}
END_TEST
 

//////////////////////////////////////////////////
START_TEST (test_kw_comp){
  printf("Running test kw comp function \n");
  const struct key left = {"this", 0};
  const struct key right = {"that", 0};
  int res;
  res = kw_comp(&left, &right);
  ck_assert_int_eq(res, 1);
}
END_TEST


//////////////////////////////////////////////////
START_TEST (test_count_comp){
  printf("Running test count comp function \n");
  const struct key left = {"this", 100};
  const struct key right = {"that", 1000};
  int res;
  res = count_comp(&left, &right);
  ck_assert_int_eq(res, -1);
}
END_TEST


//////////////////////////////////////////////////
START_TEST (test_void_swap){
  printf("Running test void swap function \n");
  struct key left = {"this", 0};
  struct key right = {"that", 0};
  struct key * keytab[] = {&left, &right};
  swap((void **) keytab, 0, 1);
  printf("[0] = %s \n\n", keytab[0]->word);
  printf("[1] = %s \n\n", keytab[1]->word);
  ck_assert_str_eq(keytab[0]->word, "that");
  ck_assert_str_eq(keytab[1]->word, "this");
}
END_TEST



//////////////////////////////////////////////////
Suite *create_sample_suite(void)
{
  printf("creating lib/count_words test suite \n");
  Suite *suite = suite_create("Sample suite");
  TCase *test_case = tcase_create("Sample test case");
  tcase_add_test(test_case, sample_test);
  tcase_add_test(test_case, test_kw_comp);
  tcase_add_test(test_case, test_count_comp);  
  tcase_add_test(test_case, test_void_swap);
  suite_add_tcase(suite, test_case);
  return suite;
}

