#include <check.h>
#include <stdlib.h>
#include "sum.h"
#include "mult.h"

START_TEST (test_sum)
{
    // function under test
    int sum1 = sum(2,2);
    int sum2 = sum(-2,2);
    int sum3 = sum(0,5);
    int sum4 = sum(5,3);
    int sum5 = sum(-1,-3);

    // verify results are as expected
    ck_assert_int_eq(sum1, 4);
    ck_assert_int_eq(sum2, 0);
    ck_assert_int_eq(sum3, 5);
    ck_assert_int_eq(sum4, 8);

    if(sum5 != -4)
        ck_abort_msg("Test failed: -1+-3 != %d\n",sum5);
}
END_TEST

START_TEST (test_mult)
{
    // function under test
    int mult1 = mult(2,2);
    int mult2 = mult(-2,2);
    int mult3 = mult(0,5);
    int mult4 = mult(5,3);
    int mult5 = mult(-1,-3);

    // verify results are as expected
    ck_assert_int_eq(mult1, 4);
    ck_assert_int_eq(mult2, -4);
    ck_assert_int_eq(mult3, 0);
    ck_assert_int_eq(mult4, 15);
    ck_assert_int_eq(mult5, 3);
}
END_TEST

Suite * arithmetic_suite(void)
{
    // create the test suite
    Suite *s = suite_create("Arithmetic Unit Tests");

    // create a test case for each unit test
    TCase *tc_sum = tcase_create("Core_sum");
    TCase *tc_mult = tcase_create("Core_mult");

    // add each unit test to its test case
    tcase_add_test(tc_sum, test_sum);
    tcase_add_test(tc_mult, test_mult);

    // add each test case to the suite
    suite_add_tcase(s, tc_sum);
    suite_add_tcase(s, tc_mult);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = arithmetic_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
