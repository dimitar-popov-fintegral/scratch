#include <check.h>
 
START_TEST (sample_test)
{
   ck_assert_int_eq(42, 42);
}
END_TEST
 
Suite *create_sample_suite(void)
{
    Suite *suite = suite_create("Sample suite");
    TCase *test_case = tcase_create("Sample test case");
    tcase_add_test(test_case, sample_test);
    return suite;
}
