#include "libjrt.h"

TestSummary test_summary = {
    .tests_run = 0,
    .tests_failed = 0,
    .tests_passed = 0,
};

int current_test_failed = 0;
int counter_assert_run = 0;

void just_run_test(void (*fn)()) {
    current_test_failed = 0;
    test_summary.tests_run++;

    fn();

    if (current_test_failed == 0) {
        test_summary.tests_passed++;
    } else {
        test_summary.tests_failed++;
    }
}

int just_print_test_result() {
    const char *test_placeholder = counter_assert_run == 1 ? "test" : "tests";
    const char *file_placeholder = test_summary.tests_run == 1 ? "file" : "files";

    printf("Ran %d %s across %d %s\n", counter_assert_run, test_placeholder, test_summary.tests_run, file_placeholder);
    printf("%d PASS\n", counter_assert_run - test_summary.tests_failed);
    printf("%d FAIL\n", test_summary.tests_failed);

    if (test_summary.tests_run == test_summary.tests_passed) {
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
