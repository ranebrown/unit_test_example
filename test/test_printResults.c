/**
 * @file        test_printResults.c
 * @authors     Rane Brown & Brian Douglass
 * @date        03-20-2016
 * @brief       Unit tests for the all functions in printResults.h
 */
#include <check.h>
#include <stdlib.h>
#include "printResults.h"

/**
 * @brief unit test for printResults(char *filename)
 */
START_TEST (test_printResults)
{
    // variables
    char filename[] = "test_trace";
    int res = 1;

    // function under test
    res = printResults(filename);

    // verify results are as expected
    ck_assert_int_eq(res, EXIT_SUCCESS);

}
END_TEST

/**
 * @brief creates a test suite that will contain all unit tests within this file.
 *
 * A test suite is created that will contain all tests within this file.
 * Next, a test case is created for each unit test. The associated unit test is added to that test case.
 * Finally, each test case is added to the suite.
 */
Suite * printResults_suite(void)
{
    // create the test suite
    Suite *s = suite_create("Print Simulation Results");

    // create a test case for each unit test
    TCase *tc_printResults = tcase_create("Core_printResults");

    // add each unit test to its test case
    tcase_add_test(tc_printResults, test_printResults);

    // add each test case to the suite
    suite_add_tcase(s, tc_printResults);

    return s;
}

/**
 * @brief main section for printResults unit tests - should not be modified excpet for the name
 *  of the function used for creating the test suite
 */
int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = printResults_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
