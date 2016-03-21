#include <check.h>
#include <stdlib.h>
#include "hello.h"

START_TEST (test_print)
{
    // function under test
    int res = hello();

    // verify results
    ck_assert_int_eq(res, EXIT_SUCCESS);
}
END_TEST

START_TEST (test_fail)
{
    // example of a test that fails
    ck_abort_msg("This test fails on purpose\n");
}
END_TEST

Suite * print_suite(void)
{
    // create the test suite
    Suite *s = suite_create("Print Unit Test");

    // create a test case for each unit test
    TCase *tc_print = tcase_create("Core_print");
    TCase *tc_fail = tcase_create("Core_fail");

    // add each unit test to its test case
    tcase_add_test(tc_print, test_print);
    tcase_add_test(tc_fail, test_fail);

    // add each test case to the suite
    suite_add_tcase(s, tc_print);
    suite_add_tcase(s, tc_fail);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = print_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
