#ifndef LIBJRT_H
#define LIBJRT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_RED "\033[0;31m"
#define COLOR_RESET "\033[0m"

typedef struct {
    int tests_run;
    int tests_failed;
    int tests_passed;
} TestSummary;

extern TestSummary test_summary;

extern int current_test_failed;
extern int counter_assert_run;

void just_run_test(void (*fn)());
int just_print_test_result();

#define ASSERT_STR_EQUAL(expected, actual)                                                                        \
    do {                                                                                                          \
        counter_assert_run++;                                                                                     \
        if ((expected) != (actual)) {                                                                             \
            fprintf(stderr, "%s[FAIL]%s Expected: %s, Actual: %s -> %s:%d\n", COLOR_RED, COLOR_RESET, (expected), \
                    (actual), __FILE__, __LINE__);                                                                \
            current_test_failed = 1;                                                                              \
        } else {                                                                                                  \
            printf("[PASS] -> %s\n", __FILE__);                                                                   \
        }                                                                                                         \
    } while (0)

#define ASSERT_STR_NOT_EQUAL(expected, actual)                                                                    \
    do {                                                                                                          \
        counter_assert_run++;                                                                                     \
        if ((expected) == (actual)) {                                                                             \
            fprintf(stderr, "%s[FAIL]%s Expected: %s, Actual: %s -> %s:%d\n", COLOR_RED, COLOR_RESET, (expected), \
                    (actual), __FILE__, __LINE__);                                                                \
            current_test_failed = 1;                                                                              \
        } else {                                                                                                  \
            printf("[PASS] -> %s\n", __FILE__);                                                                   \
        }                                                                                                         \
    } while (0)

#define ASSERT_INT_EQUAL(expected, actual)                                                                        \
    do {                                                                                                          \
        counter_assert_run++;                                                                                     \
        if ((expected) != (actual)) {                                                                             \
            fprintf(stderr, "%s[FAIL]%s Expected: %d, Actual: %d -> %s:%d\n", COLOR_RED, COLOR_RESET, (expected), \
                    (actual), __FILE__, __LINE__);                                                                \
            current_test_failed = 1;                                                                              \
        } else {                                                                                                  \
            printf("[PASS] -> %s\n", __FILE__);                                                                   \
        }                                                                                                         \
    } while (0)

#define ASSERT_INT_NOT_EQUAL(expected, actual)                                                                    \
    do {                                                                                                          \
        counter_assert_run++;                                                                                     \
        if ((expected) == (actual)) {                                                                             \
            fprintf(stderr, "%s[FAIL]%s Expected: %d, Actual: %d -> %s:%d\n", COLOR_RED, COLOR_RESET, (expected), \
                    (actual), __FILE__, __LINE__);                                                                \
            current_test_failed = 1;                                                                              \
        } else {                                                                                                  \
            printf("[PASS] -> %s\n", __FILE__);                                                                   \
        }                                                                                                         \
    } while (0)

#define ASSERT_TRUE(expected)                                                                                    \
    do {                                                                                                         \
        counter_assert_run++;                                                                                    \
        if (!(expected)) {                                                                                       \
            fprintf(stderr, "%s[FAIL]%s Expected: true -> %s:%d\n", COLOR_RED, COLOR_RESET, __FILE__, __LINE__); \
            current_test_failed = 1;                                                                             \
        } else {                                                                                                 \
            printf("[PASS] -> %s\n", __FILE__);                                                                  \
        }                                                                                                        \
    } while (0)

#define ASSERT_FALSE(expected)                                                                                    \
    do {                                                                                                          \
        counter_assert_run++;                                                                                     \
        if ((expected)) {                                                                                         \
            fprintf(stderr, "%s[FAIL]%s Expected: false -> %s:%d\n", COLOR_RED, COLOR_RESET, __FILE__, __LINE__); \
            current_test_failed = 1;                                                                              \
        } else {                                                                                                  \
            printf("[PASS] -> %s\n", __FILE__);                                                                   \
        }                                                                                                         \
    } while (0)

#define ASSERT_NULL(expected)                                                                                    \
    do {                                                                                                         \
        counter_assert_run++;                                                                                    \
        if ((expected) != NULL) {                                                                                \
            fprintf(stderr, "%s[FAIL]%s Expected: NULL -> %s:%d\n", COLOR_RED, COLOR_RESET, __FILE__, __LINE__); \
            current_test_failed = 1;                                                                             \
        } else {                                                                                                 \
            printf("[PASS] -> %s\n", __FILE__);                                                                  \
        }                                                                                                        \
    } while (0)

#define ASSERT_NOT_NULL(expected)                                                                                    \
    do {                                                                                                             \
        counter_assert_run++;                                                                                        \
        if ((expected) == NULL) {                                                                                    \
            fprintf(stderr, "%s[FAIL]%s Expected: NOT NULL -> %s:%d\n", COLOR_RED, COLOR_RESET, __FILE__, __LINE__); \
            current_test_failed = 1;                                                                                 \
        } else {                                                                                                     \
            printf("[PASS] -> %s\n", __FILE__);                                                                      \
        }                                                                                                            \
    } while (0)

#define ASSERT_PTR_EQUAL(expected, actual)                                                            \
    do {                                                                                              \
        counter_assert_run++;                                                                         \
        if ((expected) != (actual)) {                                                                 \
            fprintf(stderr, "%s[FAIL]%s Expected: %p, Actual: %p -> %s:%d\n", COLOR_RED, COLOR_RESET, \
                    (void *)(expected), (void *)(actual), __FILE__, __LINE__);                        \
            current_test_failed = 1;                                                                  \
        } else {                                                                                      \
            printf("[PASS] -> %s\n", __FILE__);                                                       \
        }                                                                                             \
    } while (0)

#define ASSERT_PTR_NOT_EQUAL(expected, actual)                                                        \
    do {                                                                                              \
        counter_assert_run++;                                                                         \
        if ((expected) == (actual)) {                                                                 \
            fprintf(stderr, "%s[FAIL]%s Expected: %p, Actual: %p -> %s:%d\n", COLOR_RED, COLOR_RESET, \
                    (void *)(expected), (void *)(actual), __FILE__, __LINE__);                        \
            current_test_failed = 1;                                                                  \
        } else {                                                                                      \
            printf("[PASS] -> %s\n", __FILE__);                                                       \
        }                                                                                             \
    } while (0)

#define ASSERT_GT(expected, actual)                                                                                \
    do {                                                                                                           \
        counter_assert_run++;                                                                                      \
        if (!((actual) > (expected))) {                                                                            \
            fprintf(stderr, "%s[FAIL]%s Expected > %d, Actual: %d -> %s:%d\n", COLOR_RED, COLOR_RESET, (expected), \
                    (actual), __FILE__, __LINE__);                                                                 \
            current_test_failed = 1;                                                                               \
        } else {                                                                                                   \
            printf("[PASS] -> %s\n", __FILE__);                                                                    \
        }                                                                                                          \
    } while (0)

#define ASSERT_LT(expected, actual)                                                                                \
    do {                                                                                                           \
        counter_assert_run++;                                                                                      \
        if (!((actual) < (expected))) {                                                                            \
            fprintf(stderr, "%s[FAIL]%s Expected < %d, Actual: %d -> %s:%d\n", COLOR_RED, COLOR_RESET, (expected), \
                    (actual), __FILE__, __LINE__);                                                                 \
            current_test_failed = 1;                                                                               \
        } else {                                                                                                   \
            printf("[PASS] -> %s\n", __FILE__);                                                                    \
        }                                                                                                          \
    } while (0)

#define ASSERT_GTE(expected, actual)                                                                                \
    do {                                                                                                            \
        counter_assert_run++;                                                                                       \
        if (!((actual) >= (expected))) {                                                                            \
            fprintf(stderr, "%s[FAIL]%s Expected >= %d, Actual: %d -> %s:%d\n", COLOR_RED, COLOR_RESET, (expected), \
                    (actual), __FILE__, __LINE__);                                                                  \
            current_test_failed = 1;                                                                                \
        } else {                                                                                                    \
            printf("[PASS] -> %s\n", __FILE__);                                                                     \
        }                                                                                                           \
    } while (0)

#define ASSERT_LTE(expected, actual)                                                                                \
    do {                                                                                                            \
        counter_assert_run++;                                                                                       \
        if (!((actual) <= (expected))) {                                                                            \
            fprintf(stderr, "%s[FAIL]%s Expected <= %d, Actual: %d -> %s:%d\n", COLOR_RED, COLOR_RESET, (expected), \
                    (actual), __FILE__, __LINE__);                                                                  \
            current_test_failed = 1;                                                                                \
        } else {                                                                                                    \
            printf("[PASS] -> %s\n", __FILE__);                                                                     \
        }                                                                                                           \
    } while (0)

#define ASSERT_MEM_EQUAL(expected, actual, size)                                                                      \
    do {                                                                                                              \
        counter_assert_run++;                                                                                         \
        if (memcmp((expected), (actual), (size)) != 0) {                                                              \
            fprintf(stderr, "%s[FAIL]%s Expected memory at %p, Actual memory at %p, Size: %zu -> %s:%d\n", COLOR_RED, \
                    COLOR_RESET, (void *)(expected), (void *)(actual), (size_t)(size), __FILE__, __LINE__);           \
            current_test_failed = 1;                                                                                  \
        } else {                                                                                                      \
            printf("[PASS] -> %s\n", __FILE__);                                                                       \
        }                                                                                                             \
    } while (0)

#define ASSERT_MEM_NOT_EQUAL(expected, actual, size)                                                                  \
    do {                                                                                                              \
        counter_assert_run++;                                                                                         \
        if (memcmp((expected), (actual), (size)) == 0) {                                                              \
            fprintf(stderr, "%s[FAIL]%s Expected memory at %p, Actual memory at %p, Size: %zu -> %s:%d\n", COLOR_RED, \
                    COLOR_RESET, (void *)(expected), (void *)(actual), (size_t)(size), __FILE__, __LINE__);           \
            current_test_failed = 1;                                                                                  \
        } else {                                                                                                      \
            printf("[PASS] -> %s\n", __FILE__);                                                                       \
        }                                                                                                             \
    } while (0)

#endif
