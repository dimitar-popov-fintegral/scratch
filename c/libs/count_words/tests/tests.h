#include <check.h>
#include "../count_words.h"
 

START_TEST (sample_test){
  printf("Running sample test function \n");
  ck_assert_int_eq(42, 42);
}
END_TEST
 
START_TEST (test_kw_comp){
  printf("Running test kw comp function \n");
  const struct key left = {"this", 0};
  const struct key right = {"that", 0};
  int res;
  res = kw_comp(&left, &right);
  ck_assert_int_eq(res, 'i' - 'a' - '0');
}
END_TEST


Suite *create_sample_suite(void)
{
  printf("creating test suite \n");
  Suite *suite = suite_create("Sample suite");
  TCase *test_case = tcase_create("Sample test case");
  tcase_add_test(test_case, sample_test);
  tcase_add_test(test_case, test_kw_comp);
  suite_add_tcase(suite, test_case);
  return suite;

}

