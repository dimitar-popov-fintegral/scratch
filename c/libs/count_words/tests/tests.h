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
START_TEST (test_qs_kw){
  printf("Running test quick sort function with kw compare \n");
  struct key one = {"c", 3};
  struct key two = {"b", 2};
  struct key the = {"a", 1};
  struct key * keytab[] = {&one, &two, &the};
  quick_sort( (void *) keytab, 0, 2, (int (*)(void *, void *)) kw_comp);
  // the above line casts the fn kw_comp to one which is
  // accepted by the quick_sort function 
  ck_assert_str_eq(keytab[0]->word, "a");
  ck_assert_str_eq(keytab[1]->word, "b");
  ck_assert_str_eq(keytab[2]->word, "c");    
}
END_TEST


//////////////////////////////////////////////////
START_TEST (test_qs_nc){
  printf("Running test quick sort function  with num. compare \n");
  struct key one = {"c", 3};
  struct key two = {"b", 2};
  struct key the = {"a", 1};
  struct key * keytab[] = {&one, &two, &the};
  quick_sort( (void *) keytab, 0, 2, (int (*)(void *, void *)) count_comp);
  ck_assert_str_eq(keytab[0]->word, "a");
  ck_assert_str_eq(keytab[1]->word, "b");
  ck_assert_str_eq(keytab[2]->word, "c");    
}
END_TEST


//////////////////////////////////////////////////
START_TEST (test_void_swap){
  printf("Running test void swap function \n");
  struct key left = {"this", 0};
  struct key right = {"that", 0};
  struct key * keytab[] = {&left, &right};
  swap((void **) keytab, 0, 1);
  ck_assert_str_eq(keytab[0]->word, "that");
  ck_assert_str_eq(keytab[1]->word, "this");
}
END_TEST


//////////////////////////////////////////////////
START_TEST (test_bs){
  printf("Running test quick sort function  with num. compare \n");
  struct key one = {"c", 3};
  struct key two = {"b", 2};
  struct key the = {"a", 1};
  struct key itm = {"c", 1};
  struct key * keytab[] = {&one, &two, &the};
  quick_sort((void *) keytab, 0, 2, (int (*)(void *, void *)) kw_comp);
  int a = __bsearch((void *) &itm, (void *) keytab, (int (*)(void *, void *)) kw_comp, 3);
  ck_assert_int_eq(a, 2);
}
END_TEST


//////////////////////////////////////////////////
Suite * create_sample_suite(void)
{
  printf("creating lib/count_words test suite \n");
  Suite *suite = suite_create("Sample suite");
  TCase *test_case = tcase_create("Sample test case");
  tcase_add_test(test_case, sample_test);
  tcase_add_test(test_case, test_kw_comp);
  tcase_add_test(test_case, test_count_comp);  
  tcase_add_test(test_case, test_void_swap);
  tcase_add_test(test_case, test_qs_kw);
  tcase_add_test(test_case, test_qs_nc);
  tcase_add_test(test_case, test_bs);
  suite_add_tcase(suite, test_case);
  return suite;
}

